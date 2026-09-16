class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                return false;
            }
        }
        return true;
    }
};
/*The function iterates through the array once, doing O(1) work per element. 
Time complexity: O(n), where n is the size of nums. 
Space complexity: O(1), since it uses a constant amount of extra space regardless of input size.*/