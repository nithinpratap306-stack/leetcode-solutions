class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=-1;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem+=k;

            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2) return true;
            }
            else{
                mp[rem]=i;
            }
        }
        return false;
    }
};
/*Time complexity: O(n), where n is the length of nums. We traverse the array once and each operation inside is O(1) on average due to the unordered_map.
Space complexity: O(min(n, k)) in the worst case, since we store at most one entry per possible remainder modulo k, up to n distinct remainders (but bounded by k if k is small). The initial mp[0] = -1 also uses constant space.*/