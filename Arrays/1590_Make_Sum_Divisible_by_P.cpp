class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        long long prefix=0;
        long long total=0;
        int ans=nums.size();
        for(int i: nums){
            total+=i;
        }
        int target=total%p;
        if(target==0) return 0;

        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];

            int rem=prefix%p;   
            int required=(rem-target+p)%p;
            if(mp.find(required)!=mp.end()){
                ans=min(ans, i-mp[required]);
            }
            mp[rem]=i;
        }
        return (ans==nums.size())? -1:ans;
    }
};
/*Time complexity: O(n), where n is the length of nums. Each element is processed once, and map lookups/inserts are average O(1).

Space complexity: O(n) in the worst case, due to the unordered_map storing up to n distinct prefix remainders. In practice, remainders are in [0, p-1], so space is O(min(n, p))*/