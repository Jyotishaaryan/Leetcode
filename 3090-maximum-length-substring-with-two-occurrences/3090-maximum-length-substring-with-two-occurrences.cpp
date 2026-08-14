class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int start = 0 , end = 0 ;
        map<char ,int> freq;
        int maxlength = 0;
        while(end < n)
        {
            freq[s[end]]++;
            while(freq[s[end]] > 2)
            {
                freq[s[start]]--;
                s[start];
                start++;
            }
            maxlength = max(maxlength,end-start+1);
            end++;
        }
        return maxlength;
    }
};