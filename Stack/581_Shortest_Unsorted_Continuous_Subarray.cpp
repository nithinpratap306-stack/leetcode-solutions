class Solution {
public:
    // Time complexity: O(n). Each element is pushed and popped at most once in each of the two passes, so overall linear.

    // Space complexity: O(n) in the worst case for the stack, since it can hold up to n indices. However, in practice it uses extra stack space proportional to the subarray length, not the whole array.
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int>st;
        int l=INT_MAX,r=INT_MIN;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                l=min(l,st.top());
                st.pop();
            }
            st.push(i);
        }
        if(l==INT_MAX)return 0;

        stack<int>().swap(st);

        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                r=max(r,st.top());
                st.pop();
            }
            st.push(i);
        }
        return (r-l+1);
    }
};