class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // - Time complexity: O(n) in total, since each index is pushed and popped once.
        // - Space complexity: O(n) in the worst case for the stack, plus O(1) extra variables.
        stack<int>st;
        int mx=0;
        int n=heights.size();
        for(int i=0;i<=n;i++){
            int curr=(i==n)?0:heights[i];
            while(!st.empty() && curr<heights[st.top()]){
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                mx=max(mx,width*height);
            }
            st.push(i);
        }
        return mx;
    }
};