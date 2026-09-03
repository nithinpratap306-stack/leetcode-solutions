class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        for(int i:nums){
            total+=i;
        }
        int left=0;
        for(int i=0;i<nums.size();i++){
            int right=total-left-nums[i];
            if(left==right)return i;
            left+=nums[i];
        }
        return -1;
    }
};
/*Time complexity: O(n), since we traverse the array twice at most (one pass to compute total, one pass to find the pivot).

Space complexity: O(1), only a few scalar variables are used.*/