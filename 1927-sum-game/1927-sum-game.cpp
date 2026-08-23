class Solution {
public:
    bool sumGame(string nums) {
        int q0 = 0 , n0 = 0 , q1 = 0 , n1 = 0;
        int n =nums.length();
        for(int i = 0 ; i< n/2; i++)
        {
            if(nums[i]=='?') q0 += 1;
            else n0+=nums[i] - '0';
        }
        for(int i = n/2 ; i < n; i++)
        {
            if(nums[i]=='?') q1 += 1;
            else n1+=nums[i]-'0';
        }
        return (q0+q1)%2 == 1 || n0-n1 != ((q1-q0)/2)*9;
    }
};