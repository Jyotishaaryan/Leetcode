class Solution {
public:
    double solve(double x, long n)
    {
        if(n==0)
        {
            return 1;

        }
        double halfPow = myPow(x,n/2);
        double sqPow = halfPow * halfPow;
        if(n<0)
        {
            return solve(1/x,-n);
        }
        if(n%2 != 0)
        {
            return x*sqPow;
        }
        else{
            return sqPow;
        }
    }
    double myPow(double x, int n) {
        return solve(x, (long)n);
    }
};