class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int x: nums){
            freq[x]++;
        }
        sort(nums.begin(), nums.end(),
        [&](int a, int b){
                if(freq[a]!=freq[b]){
                    return freq[a]<freq[b];
                }
                return a>b;
            }
        );
        return nums;
    }
};
/*Time complexity:
- Building the frequency map: O(n) on average.
- Sorting the n elements with a custom comparator: O(n log n).
Overall: O(n log n) time on average.

Space complexity:
- Frequency map stores at most O(n) distinct integers: O(n) space.
- Sorting uses in-place modifications on the input vector (no extra vector), plus O(1) or O(log n) stack space for recursion depending on sort implementation.
Total: O(n) auxiliary space in the worst case.*/