class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n-1, pos =n-1;
        vector<int>v(n);
        while(i<=j)
        {
            if(abs(nums[i])  < abs(nums[j]))
            {
                v[pos] = nums[j]*nums[j];
                j--;
                pos--;
            }
            else
            {
                v[pos] = nums[i]*nums[i];
                i++;
                pos--;
            }
        }
        return v;
    }
};