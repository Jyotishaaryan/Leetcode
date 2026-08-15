class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xors = 0;
        int n = nums.size();
        bool solve = true;
        for(int i = 0; i<n; i++)
        {
            xors ^= nums[i];
            if(xors != 0)
            {
                solve = false;

            }
            
        }
        if(solve == true) return 0; 
        int res = (xors == 0) ? n-1 : n;

        return res;
        
    }
};