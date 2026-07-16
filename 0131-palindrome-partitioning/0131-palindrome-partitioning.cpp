class Solution {
public:
    bool ispalindrome(string s)
    {
        int n = s.length();
        int l = 0;
        int r = n-1;
        while(l <= r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;

    }
    void solve(string &s, int idx, vector<string> &curr, vector<vector<string>> &res)
    {
        if(idx == s.length())
        {
            res.push_back(curr);
            return;
        }
    for(int i = idx; i < s.length(); i++)
    {
        if(ispalindrome(s.substr(idx, i-idx+1)))
        {
            
            curr.push_back(s.substr(idx , i-idx+1));
            solve(s,i+1,curr,res);
            curr.pop_back();
        }
    }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> res;
        solve(s , 0 , curr , res);
        return res;
    }
};