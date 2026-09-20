class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int sum = 0;
        for(int i=0; i < n; i++)
        {
            char a = s[i];
            int alphabet = (a - 'a')+1;
            int reverse = 27 - alphabet;
            int position = i+1;
            int prod = reverse * position;
            sum += prod;
        }
        return sum;
        
    }
};