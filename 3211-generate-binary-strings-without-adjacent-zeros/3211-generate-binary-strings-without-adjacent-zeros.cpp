class Solution {
public:
    void vS(int n, int last, string ans,vector<string>&res) {
        if(n==0)
        {
           res.push_back(ans);
           return;
            
        }
        if(last!=0)
        {
            vS(n-1,0,ans+'0',res);
            vS(n-1,1,ans+'1',res);
        }
        else
        {
            vS(n-1,1,ans+'1',res);

        }
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        
        vS(n,1,"",res);
        return res;
    }
};