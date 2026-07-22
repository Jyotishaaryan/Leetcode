class Solution {
public:
int helper(vector<int>& nums, int goal)
{
        int left = 0; 
        int sum = 0; 
        int cnt = 0;
        int right = 0;
        while(right< nums.size())
        {
            sum+=nums[right];
            while(sum > goal && left <= right)
            {
                sum -=nums[left];
                left = left+1;
            }
            if(sum <= goal)
            {
                cnt += right-left+1;
            }
            right++;
        }
        return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return helper(nums, goal) - helper(nums,goal-1);
       
    }
};