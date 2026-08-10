class Solution {
public:
    vector<int> dp;
    bool winnerSquareGame(int n) {
        dp.resize(n+1 ,-1);
        return func(n);
        
    }
    bool func(int n)
    {
        if(n == 0) return false;
        if(dp[n]!=-1) return dp[n];

        for(int i = 1; i*i<=n ; i++)
        {
            if(func(n-i*i) == false)
            {
                return dp[n] = 1;
            }
        }
        return dp[n] = 0;
    }
};