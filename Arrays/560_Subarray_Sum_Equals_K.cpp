class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k) ans++;
            }
        }
        return ans;
    }
};
/*Time complexity: O(n^2) in the worst case, due to the nested loops that examine all subarrays of the input array of length n.
Space complexity: O(1) extra space, since only a few integer variables are used regardless of input size.*/