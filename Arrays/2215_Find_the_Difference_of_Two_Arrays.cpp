class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<vector<int>> ans(2);

        for (int num : set1) {
            if (!set2.contains(num)) {
                ans[0].push_back(num);
            }
        }

        for (int num : set2) {
            if (!set1.contains(num)) {
                ans[1].push_back(num);
            }
        }

        return ans;
    }
};
/*- Time complexity: O(n + m), where n is size of nums1 and m is size of nums2. Building the two unordered_sets takes O(n) and O(m). Iterating over set1 and set2 to check membership is O(n) + O(m) on average, giving total O(n + m) average time. Worst-case with hash collisions can degrade to O((n + m) * k) but average case is O(n + m).

- Space complexity: O(n + m) for storing the two sets plus the resulting output, which in the worst case could include all elements from both arrays.*/