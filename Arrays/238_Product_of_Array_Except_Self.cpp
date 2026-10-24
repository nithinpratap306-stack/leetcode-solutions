class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
        int x=1;
        int right=1;
        for(int i=0;i<nums.size();i++){
            ans[i]=x;
            x*= nums[i];
        }
        x=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=x;
            x*=nums[i];
        }
        return ans;
    }
};
/*Time complexity: O(n) — the function makes two linear passes over the array.

Space complexity: O(1) auxiliary space (besides the output array), since it uses a few extra variables and writes results into the output vector.*/