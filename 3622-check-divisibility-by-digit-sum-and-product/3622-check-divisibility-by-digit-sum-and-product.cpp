class Solution {
public:
    int getdigit(int n)
    {
        int temp = n;
        int prod = 1;
        int sum = 0;
        while(temp != 0)
        {
            int digit = temp % 10;
            prod *= digit;
            sum += digit;
            temp = temp / 10;
        }
        return prod + sum;
    }
    bool checkDivisibility(int n) {
        int ans  = getdigit(n);
        if(n % ans == 0)return true;
        else
        {
            return false;
        }
        
    }
};