class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& comb, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break; // pruning

            comb.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, comb, ans); // move forward
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(candidates, target, 0, comb, ans);
        return ans;
    }
};
