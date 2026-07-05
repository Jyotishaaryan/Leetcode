class Solution {
public:
    void solve(int start, int k, int n, vector<vector<int>>& ans, vector<int>& comb) {
        if(k == 0 && n == 0) {
            ans.push_back(comb);
            return;
        }

        for(int num = start; num <= 9; num++) {
            if(num > n) break; // pruning

            comb.push_back(num);
            solve(num+1, k-1, n-num, ans, comb);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(1, k, n, ans, comb);
        return ans;
    }
};
