
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                              vector<int>& load) {
        
        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {completion time, server ID}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Free servers whose requests are completed
            while (!busy.empty() &&
                   busy.top().first <= arrival[i]) {
                
                available.insert(busy.top().second);
                busy.pop();
            }

            // All servers are busy
            if (available.empty()) {
                continue;
            }

            int preferred = i % k;

            // Find the first available server >= preferred
            auto it = available.lower_bound(preferred);

            // Wrap around if no such server exists
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request
            available.erase(it);
            count[server]++;

            // Store completion time
            busy.push({arrival[i] + load[i], server});
        }

        // Find maximum number of requests
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
