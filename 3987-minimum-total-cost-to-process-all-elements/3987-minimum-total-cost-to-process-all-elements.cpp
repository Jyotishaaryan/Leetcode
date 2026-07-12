class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9+7;
        long long res = 0;
        long long resources = k;
        long long ops = 0; // number of operations performed

        for (int x : nums) {
            if (resources < x) {
                // how many operations we need
                long long need = (x - resources + k - 1) / k; // ceil division

                // compute cost safely with __int128
                __int128 cost = (__int128)need * (2*ops + need + 1) / 2;

                // reduce modulo immediately
                res = (res + (long long)(cost % MOD)) % MOD;

                ops += need;
                resources += need * k;
            }
            resources -= x;
        }
        return (int)(res % MOD);
    }
};
