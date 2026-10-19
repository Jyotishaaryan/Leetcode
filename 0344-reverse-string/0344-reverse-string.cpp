class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> str;
        for(int i= 0 ; i<s.size(); i++)
        {
            str.push(s[i]);
        }
        for(int i= 0 ; i<s.size(); i++)
        {
            s[i] = str.top();
            str.pop();
        }
        
    }
};