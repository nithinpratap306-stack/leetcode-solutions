class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        // vector<long long>prefix(n+1,0);
        long long total=0;
        for(int i: nums) total+=i;

        int cnt=0;
        long long prefix=nums[0];
        for(int i=1;i<n;i++){
            long long left=prefix;
            long long right=total - prefix;
            if(left>=right) cnt++;
            prefix+=nums[i];
        }
        return cnt;
    }
};
/*Time complexity: O(n). The loop traverses the array once to compute the total, and then a single pass from index 1 to n-1 updates a running prefix and checks the split condition.
Space complexity: O(1). Only a few scalar variables are used (total, prefix, cnt), no extra data structures proportional to n.*/