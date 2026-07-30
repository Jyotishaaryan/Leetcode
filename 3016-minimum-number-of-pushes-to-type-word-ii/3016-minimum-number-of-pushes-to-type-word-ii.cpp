class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26,0);
        for(char ch : word)
        {
            mp[ch - 'a']++;
        }
        int result = 0;
        sort(begin(mp) , end(mp) , greater<int>());

        for(int i = 0; i< 26; i++)
        {
            int freq = mp[i];

            int ans = i/8+1;
            result+= ans * freq;
        }
        return result;
    }
};