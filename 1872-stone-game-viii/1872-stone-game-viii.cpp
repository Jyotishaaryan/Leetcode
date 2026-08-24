class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixsum(n,0);
        prefixsum[0] = stones[0];
        for(int i = 1; i < n; i++)
        {
            prefixsum[i] = prefixsum[i-1] + stones[i];

        }
        vector<int> t(n,0);

        t[n-1] = prefixsum[n-1];

        for(int i = n-2 ; i>=1; i--)
        {
            int take = prefixsum[i] - t[i+1];
            int skip = t[i+1];

            t[i] = max(take,skip);
        }
        return t[1];
        
    }
};