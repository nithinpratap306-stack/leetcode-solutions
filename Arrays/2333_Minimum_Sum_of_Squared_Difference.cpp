class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        long long k = 1LL * k1 + k2;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        if (k >= total) return 0;

        sort(diff.rbegin(), diff.rend());

        long long level = diff[0];
        int count = 1;

        for (int i = 1; i < n; i++) {
            long long next = diff[i];
            long long cost = count * (level - next);

            if (k >= cost) {
                k -= cost;
                level = next;
                count++;
            } else {
                break;
            }
        }

        long long q = k / count;
        long long r = k % count;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long val;

            if (i < count) {
                val = level - q - (i < r);
            } else {
                val = diff[i];
            }

            ans += val * val;
        }

        return ans;
    }
};
/*Complexity: (O(nog n)) time and (O(n)) extra space.*/