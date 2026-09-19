class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]) count++;
            }
        }
        return count;
    }
};
/*The code uses two nested loops over the array.
The outer loop runs n times and the inner loop runs up to n−i−1 times, giving a time complexity of O(n^2). 
The space usage is O(1) besides the input array, since it only uses a few integer variables (no extra data structures).*/