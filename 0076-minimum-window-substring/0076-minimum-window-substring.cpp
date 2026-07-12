class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char,int> need, have;
        for (char c : t) need[c]++;

        int required = need.size();   // distinct chars needed
        int formed = 0;               // distinct chars satisfied
        int l = 0, r = 0;
        int minLen = INT_MAX, start = 0;

        while (r < s.size()) {
            char c = s[r];
            have[c]++;
            if (need.count(c) && have[c] == need[c]) {
                formed++;
            }

            // Try to shrink
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                char leftChar = s[l];
                have[leftChar]--;
                if (need.count(leftChar) && have[leftChar] < need[leftChar]) {
                    formed--;
                }
                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
