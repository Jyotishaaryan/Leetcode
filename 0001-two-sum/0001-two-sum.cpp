class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mpp;
        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int rem = target - num;
            if(mpp.find(rem) != mpp.end())
            {
                return {i, mpp[rem]};
            }

            mpp[num] = i; 
        }

        return {-1,-1};
        
    }
};