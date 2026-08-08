class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n=cars.size();
        vector<double>ans(n,-1.00000);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && cars[i][1]<=cars[st.top()][1]){
                st.pop();
            }
            while(!st.empty()){
                double ct=(double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
                if(ct<=ans[st.top()] || ans[st.top()]==-1){
                    ans[i]=ct;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
/*Time complexity: Each car index is pushed onto the stack once and popped at most once, and each pair is examined at most a constant number of times. Overall O(n), where n is the number of cars.
Space complexity: O(n) for the stack plus the answer vector.*/