class Solution {
public:
    int maxDepth(string s) {
        int res =0; 
        int curr =0;
        for (char &ch : s)
        {
            if(ch == '(')
            {
                curr++;
                res = max(res, curr);
            }
            if(ch == ')') curr--;

        }
        return res;
        
    }
};