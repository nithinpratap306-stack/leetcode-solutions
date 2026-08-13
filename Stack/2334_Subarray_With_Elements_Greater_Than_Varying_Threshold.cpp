class Solution {
public:
    vector<int> fpse(vector<int>nums){
        stack<int>st;
        vector<int>pse(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }
            if(!st.empty())pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> fnse(vector<int>nums){
        stack<int>st;
        vector<int>nse(nums.size(),nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[i]<nums[st.top()]){
                st.pop();
            }
            if(!st.empty())nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    int validSubarraySize(vector<int>& nums, int threshold) {
        vector<int>pse=fpse(nums);
        vector<int>nse=fnse(nums);
        for(int i=0;i<nums.size();i++){
            long len=nse[i]-pse[i]-1;
            if(nums[i]*len>threshold)return len;
        }
        return -1;
    }
};
/*The solution uses monotonic stacks to compute for each index i:
- pse[i]: index of previous smaller or equal element (or -1)
- nse[i]: index of next smaller element (or n)

Both computations are linear in the array size.

- fpse: Each index is pushed/popped at most once → O(n) time, O(n) space for the stack and result.
- fnse: Similarly O(n) time and O(n) space.

validSubarraySize then iterates once over nums to compute len = nse[i] - pse[i] - 1 and checks the condition, which is O(n) time and uses O(1) extra space beyond the two result vectors.

Total:
- Time: O(n)
- Space: O(n) (for pse and nse, plus the stack during computation; the dynamic extra space aside from input is O(n))*/