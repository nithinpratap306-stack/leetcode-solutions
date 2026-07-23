class Solution {
public:
// Time complexity: O(n). Each index is pushed onto the stack once and popped at most once, and each pair of i and stack pop is processed in O(1).
// Space complexity: O(n) in the worst case, due to the stack storing indices of bars.
    int trap(vector<int>& height) {
        int water=0;
        stack<int>st;
        for(int i=0;i<height.size();i++){
            while(!st.empty() && height[i]>height[st.top()]){
                int bottom=st.top();
                st.pop();
                if(st.empty()) break;
                int left=st.top();
                int width=i-left-1;

                int boundedheight=min(height[left],height[i])-height[bottom];
                water+=width*boundedheight;
            }
            st.push(i);
        }
        return water;
    }
};