class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=nums[0];
        int mx=sum;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                sum+=nums[i];
            }
            else{
                sum=nums[i];
            }
            mx=max(mx,sum);
        }
        return mx;
    }
};
/*Time complexity: O(n), where n is the length of nums. The loop traverses the array once with constant-time work per element.

Space complexity: O(1), aside from the input array, since only a few scalar variables (sum, mx, and loop index) are used.*/