class Solution {
public:
    int gcd(int a , int b)
    {
        if(b == 0) return a;
        return gcd(b , a%b);
    }
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int num : nums)
        {
            mini = min(mini , num);
            maxi = max(maxi , num);
        }
        return gcd(mini , maxi);
    }
};