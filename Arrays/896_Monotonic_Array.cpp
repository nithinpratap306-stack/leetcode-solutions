class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc=true;
        bool dec=true;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                dec=false;
            }
            else if(nums[i] < nums[i-1]){
                inc=false;
            }
        }
        return (dec||inc);
    }
};
/*Time complexity: O(n), where n is the length of the input vector. The loop traverses the array once.
Space complexity: O(1), since only a few boolean variables are used regardless of input size.*/