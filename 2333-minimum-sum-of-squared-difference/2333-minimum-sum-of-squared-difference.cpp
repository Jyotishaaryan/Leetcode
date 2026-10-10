
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int maxDiff = 0;
        long long totalDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            totalDiff += diff[i];
        }

        // Enough operations to make every difference zero
        if (k >= totalDiff)
            return 0;

        // Binary search the maximum allowed difference
        int low = 0, high = maxDiff;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid)
                    need += d - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int limit = low;
        long long need = 0;
        long long ans = 0;
        long long count = 0;

        for (int d : diff) {
            if (d > limit)
                need += d - limit;

            int reduced = min(d, limit);
            ans += 1LL * reduced * reduced;

            if (d >= limit)
                count++;
        }

        // Use remaining operations to reduce limit to limit - 1
        long long remaining = k - need;

        ans -= remaining * (2LL * limit - 1);

        return ans;
    }
};