class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefix=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            int remove=prefix-k;
            cnt+=mp[remove];
            mp[prefix]++;
        }
        return cnt;
    }
};
/*Time complexity: O(n), where n is the length of nums. Each element is processed once and map lookups/updates are average O(1).
Space complexity: O(n) in the worst case, due to storing prefix sums in the unordered_map. In typical cases with many distinct prefix values, the map size grows with n.*/