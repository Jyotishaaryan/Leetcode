class Solution {
public:
    string result = ""; 
    bool solve(string curr , vector<int> &cnt , string target, int i, bool greater)
    {
        if(i ==target.length())
        {
            if(greater)
            {
                result = curr;
                return true;

            }
            return false;
        }

        for(char ch ='a'; ch <= 'z'; ch++)
        {
            if(cnt[ch-'a'] == 0) continue;
            if(greater == false && ch < target[i]) continue;

            curr.push_back(ch);
            cnt[ch-'a']--;

            bool isgreater =greater || ch > target[i];
            if(solve(curr, cnt ,target, i+1, isgreater))
            {
                return true;
            }

            curr.pop_back();
            cnt[ch-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26,0);

        for(char &ch : s)
        {
            cnt[ch-'a']++;
        }
        string curr = "";
        

        solve(curr , cnt , target, 0, false);
        return result;

    }
};