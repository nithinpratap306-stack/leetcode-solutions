class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>>bucket(nums.size()+1);
        unordered_map<int,int>freq;
        for(int x: nums){
            freq[x]++;
        }
        for(const auto& [key,value]: freq){
            bucket[value].push_back(key);
        }
        vector<int>ans;
        for(int i=nums.size();i>0 && ans.size()<k;i--){
            for(int x: bucket[i]){
                ans.push_back(x);
                if(ans.size()==k) break;
            }
        }
        return ans;
    }
};
/*Time complexity:
- Building the frequency map: O(n), where n is the size of nums.
- Filling the buckets: O(number of distinct keys) ≤ O(n).
- Collecting top k elements: In the worst case, we may traverse buckets from n down to 1 and push up to k elements, which is O(n) in the worst case if k is large relative to n, but typically O(n) overall.
Overall time: O(n).

Space complexity:
- The frequency map stores at most n entries: O(n).
- The bucket vector has size n+1, and stores each distinct key exactly once: O(n).
- The result vector stores up to k elements: O(k).
Overall space: O(n).*/