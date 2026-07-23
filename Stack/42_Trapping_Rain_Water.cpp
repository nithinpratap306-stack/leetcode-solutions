class Solution {
public:
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