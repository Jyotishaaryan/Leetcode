
class Solution {
    static const int LOG = 17;

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth, tin, tout, bit;
    int timer, n;

    void add(int i, int val) {
        for (; i <= n; i += i & -i) {
            bit[i] ^= val;
        }
    }

    int prefixXor(int i) {
        int ans = 0;
        for (; i > 0; i -= i & -i) {
            ans ^= bit[i];
        }
        return ans;
    }

    void rangeUpdate(int l, int r, int val) {
        add(l, val);
        if (r + 1 <= n) add(r + 1, val);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k)) {
                u = up[k][u];
            }
        }

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        adj.assign(n, {});
        up.assign(LOG, vector<int>(n, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        bit.assign(n + 2, 0);
        timer = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Iterative DFS to avoid stack overflow
        vector<int> parent(n, -1);
        vector<int> order;
        order.reserve(n);

        parent[0] = 0;
        order.push_back(0);

        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                order.push_back(v);
            }
        }

        for (int u : order) {
            up[0][u] = parent[u];

            for (int k = 1; k < LOG; k++) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }

        // Euler tour using iterative DFS
        vector<int> idx(n, 0);
        vector<int> st = {0};

        while (!st.empty()) {
            int u = st.back();

            if (idx[u] == 0) {
                tin[u] = ++timer;
            }

            if (idx[u] == (int)adj[u].size()) {
                tout[u] = timer;
                st.pop_back();
                continue;
            }

            int v = adj[u][idx[u]++];

            if (v != parent[u]) {
                st.push_back(v);
            }
        }

        // Initialize character parity masks
        for (int u = 0; u < n; u++) {
            int mask = 1 << (s[u] - 'a');
            rangeUpdate(tin[u], tout[u], mask);
        }

        vector<bool> ans;

        for (const string &q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');

                int change = oldMask ^ newMask;

                rangeUpdate(tin[u], tout[u], change);
                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int mask = prefixXor(tin[u])
                         ^ prefixXor(tin[v])
                         ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
