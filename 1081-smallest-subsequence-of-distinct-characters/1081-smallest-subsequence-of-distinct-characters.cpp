class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> vis(26,0), num(26,0);

        for(char ch:s)
            num[ch-'a']++;

        string stk="";

        for(char ch:s){

            int idx=ch-'a';

            if(!vis[idx]){

                while(!stk.empty() && stk.back()>ch){

                    int top_idx=stk.back()-'a';

                    if(num[top_idx]>0){

                        vis[top_idx]=0;
                        stk.pop_back();

                    }else{
                        break;
                    }
                }

                vis[idx]=1;
                stk.push_back(ch);
            }

            num[idx]--;
        }

        return stk;
    }
};