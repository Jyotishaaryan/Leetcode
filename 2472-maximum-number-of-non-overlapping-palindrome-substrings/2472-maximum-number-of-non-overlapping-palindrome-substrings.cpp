class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool ispalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int k, int i, int j) {
        if (i >= n || j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (ispalindrome(s, i, j)) {
            int take = 1 + solve(s, k, j + 1, j + k);
            int grow = solve(s, k, i, j + 1);
            int slide = solve(s, k, i + 1, j + 1);

            return dp[i][j] = max({take, grow, slide});
        }

        int grow = solve(s, k, i, j + 1);
        int slide = solve(s, k, i + 1, j + 1);

        return dp[i][j] = max(grow, slide);
    }

    int maxPalindromes(string s, int k) {
        n = s.length();

        if (k == 1)
            return n;

        dp.assign(n, vector<int>(n, -1));

        return solve(s, k, 0, k - 1);
    }
};