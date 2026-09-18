class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i+=2){
            if(nums[i]!=nums[i+1]){
                return false;
            }
        }
        return true;
    }
};
/*The function sorts the array first, which takes O(n log n) time, where n is nums.size().
 After sorting, it does a single linear pass in O(n) time to check pairs.
 Overall time complexity is O(n log n).
 The extra space usage is O(1) beyond the input array (in-place sort).
 If the sort uses extra space, the auxiliary space would be O(n) for typical sort implementations, but in-place sort implies O(1) auxiliary space.
*/