
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            int right = 0;

            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int temp = right;
                    right = dp[j];
                    dp[j] = temp;
                } else {
                    int ways = (right + dp[j]) % MOD;
                    right = ways;
                    dp[j] = ways;
                }
            }
        }

        return dp[n - 1];
    }
};
