class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        int currSum= 0;
        while(l < r)
        {
            currSum = numbers[l] + numbers[r]; 
            if(currSum < target)
            {
                l+=1;
            }
            else if(currSum > target)
            {
                r-=1;
            }
            else return {l+1,r+1};
        }
        return {}; 
        
    }
};