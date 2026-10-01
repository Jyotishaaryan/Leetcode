class Solution {
public:
    bool isValid(string str) {
        stack <char> s;
        for(int i = 0; i < str.size(); i++)
        {
            char ch =str[i];
            if(ch=='('||ch == '{'|| ch == '[')
            {
                s.push(ch);
            }
            else {
                if(s.empty()) return false;
            
            char top = s.top();
            if((top == '('&& ch == ')') ||(top == '{'&& ch == '}')||(top == '['&& ch == ']'))
            {
                s.pop();
            }
            else return false;
            }
        }
        if(s.empty()) return true;
        else return false;
        
    }
};