class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int ls[3] = {-1,-1,-1};
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            ls[s[i] - 'a'] = i;
            if(ls[0] != -1 && ls[1] != -1 && ls[2] != -1)
            {
                cnt = cnt + (1+min(ls[0],min(ls[1],ls[2])));
            }
        }
        return cnt;
    }
};