class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i: nums){
            freq[i]++;
        }
        int comp=nums.size()/3;
        nums.clear();
        for(const auto&[k,v]:freq){
            if(v>comp) nums.push_back(k);
        }
        return nums;
    }
};
/*Time complexity: O(n) on average, where n is the number of elements in nums. We iterate once to build the frequency map and then iterate over the map entries (at most n distinct keys), which is still O(n) on average.

Space complexity: O(m), where m is the number of distinct elements in nums (in the worst case m = n). The frequency map stores counts for each distinct number. The result vector uses O(k) space where k is the number of elements that appear more than n/3 (0 or 1 or 2). Overall auxiliary space is O(m).*/