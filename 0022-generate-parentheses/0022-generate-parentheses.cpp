class Solution {
public:
    void solve(int n , int open, int close , string ans, vector<string> &res)
    {
        if(ans.size() == 2*n)
        {
            res.push_back(ans);
            return;
        }
        if(open < n) solve(n, open + 1, close , ans + '(' ,res);
        if(close < open) solve(n, open, close + 1 , ans + ')' ,res);
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string ans = "";
        solve(n, 0, 0, ans ,res);
        return res;
    }
};