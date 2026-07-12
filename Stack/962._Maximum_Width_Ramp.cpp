class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        //- Time complexity: O(n). Each index is pushed onto the stack at most once and popped at most once, plus a linear backward pass over the array.
        //- Space complexity: O(n) in the worst case, due to the stack storing indices of a non-increasing prefix of nums.


        int mx=0;
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || nums[i]<nums[st.top()]){
                st.push(i);
            }
        }

        for(int j=nums.size()-1;j>=0;j--){
            while(!st.empty() && nums[j]>=nums[st.top()]){
                mx=max(mx,j-st.top());
                st.pop();
            }
        }
        return mx;
    }
};