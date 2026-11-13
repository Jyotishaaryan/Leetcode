
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        deque<pair<int, int>> dq;
        long long cost = 0;
        long long ans = 0;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            int cnt = 1;

            // Merge smaller blocks
            while (!dq.empty() && dq.back().first < num) {
                int val = dq.back().first;
                int freq = dq.back().second;
                dq.pop_back();

                cnt += freq;
                cost += 1LL * (num - val) * freq;
            }

            dq.push_back({num, cnt});

            // Shrink window if cost exceeds k
            while (cost > k) {
                int val = dq.front().first;
                int freq = dq.front().second;

                cost -= val - nums[j];

                if (freq == 1) {
                    dq.pop_front();
                } else {
                    dq.front().second--;
                }

                j--;
            }

            // Count valid subarrays
            ans += j - i + 1;
        }

        return ans;
    }
};
