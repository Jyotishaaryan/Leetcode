class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int n = nums.size();
        int low = 0 , high = n-1;
        while(low <= high)
        {
            int mid = (low+high)>>1;
            if(target == nums[mid])
            {
                return true;
            }
            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low+=1;
                high-=1;
                continue;
            }
            if(nums[mid] >= nums[low])
            {
                if(nums[low] <=target && nums[mid]>=target)
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            if(nums[mid] <= nums[high])
            {
                if(nums[mid] <=target && nums[high]>=target)
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
        }
       return false; 
        
    }
};