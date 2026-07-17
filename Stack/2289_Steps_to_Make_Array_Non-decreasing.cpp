class Solution {
public:
// Time complexity: O(n). Each element is pushed onto the stack once and popped at most once, so the total number of stack operations is linear in the input size.

// Space complexity: O(n) in the worst case. The stack can hold up to n elements if the array is strictly decreasing, leading to linear auxiliary space.
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>>st;
        int mx=0;
        for(int i=nums.size()-1;i>=0;i--){
            int count=0;
            while(!st.empty() && st.top().first<nums[i]){
                count=max(count+1,st.top().second);
                st.pop();
            }
            mx=max(count,mx);
            st.push({nums[i],count});
            // cout<<nums[i]<<" "<<count<<endl;
        }
        return mx;
    }
};