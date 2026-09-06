class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])-1<nums.size() && nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1]*=-1;
            }
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
/*Time complexity: O(n), where n is the size of the input array. The algorithm traverses the array twice (one pass to mark and one pass to collect results), each in linear time.
Space complexity: O(1) extra space (disregarding the output space). It uses only a few integer variables, and the input array is modified in place to encode the information. The output list stores up to n elements in the worst case.*/