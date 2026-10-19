class Solution {
public:
    bool isPalindrome(string s) {
        string buffer = "";
        for(char c : s)
        {
            if(isalnum(c))
            {
                buffer += tolower(c);
            }
        }
        int n  = buffer.length();
        for(int i = 0; i < n; i++)
        {
            if(buffer[i] != buffer[n-i-1])
            {
                return false;
            }
        }

        return true;
        
    }
};