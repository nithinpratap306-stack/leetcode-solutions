class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        int n=nums.size();
        for(int num: nums){
            if(num!=val){
                nums[k++]=num;
            }
        }
        return k;
    }
};
/*Time complexity: O(n), where n is the length of nums. The loop visits each element once.
Space complexity: O(1) extra space (in-place, aside from the input array). It uses a few integer variables for indices.*/