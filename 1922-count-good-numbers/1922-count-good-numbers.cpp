class Solution {
public:
    long long M  = 1e9 + 7;
    int solve(long long x , long long  n)
    {
        if(n == 0) return 1;
        long halfpow = solve(x,n/2);
        long long sqpow = halfpow * halfpow;

        if(n<0)
        {
            return solve(1/x,-n);
        }
        if(n % 2 != 0)
        {
            return (x*sqpow) % M;
        }
        else
        {
            return sqpow % M;
        }
    }
    int countGoodNumbers(long long n) {
        return ((long long)solve(5,(n+1)/2)*solve(4,n/2))%M;
    }
};