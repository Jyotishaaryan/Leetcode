class Solution {
public:
    void solve(int n , string ans, vector<string> &res)
    {
        if(ans.size() == n)
        {
            res.push_back(ans);
            return;
        }
        solve(n , ans + '1', res);
        if(ans.empty() || ans.back() != '0')
        {
            solve(n , ans + '0', res);

        }
        
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        string ans = "";
        solve(n , ans , res);
        return res;
        
    }
};