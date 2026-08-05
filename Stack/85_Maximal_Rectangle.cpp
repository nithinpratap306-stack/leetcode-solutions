class Solution {
public:
    int hist(vector<int>heights){
        stack<int>st;
        int mx=0;
        for(int i=0;i<=heights.size();i++){
            int curr=(i==heights.size())? 0:heights[i];
            while(!st.empty() && curr<heights[st.top()]){
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }
                else width=i-st.top()-1;
                mx=max(mx,height*width);
            }
            st.push(i);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int answer=-1;
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int>heights(c,0);

        for(int i=0;i<r;i++){

            for(int j=0;j<c;j++){

                if(i!=0 && matrix[i][j]!='0'){
                    heights[j]+=(matrix[i][j]-'0');
                }
                else heights[j]=matrix[i][j]-'0';
            }
            
            int area=hist(heights);
            answer=max(area,answer);
        }
        return answer;
    }
};
/*Time complexity:
    - For each row i (r rows), we update the heights array in O(c) time.
    - For each updated heights, hist() runs in O(c) time (standard monotonic stack for histogram).
    - Total time: O(r * c) for updating heights plus O(r * c) for hist calls, i.e., O(r * c).

    Space complexity:
    - We use a single heights vector of size c and a stack inside hist which at worst holds O(c) elements.
    - Overall space: O(c).*/
    