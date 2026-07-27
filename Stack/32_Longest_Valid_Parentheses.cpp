class Solution {
public:
    int longestValidParentheses(string s) {
        // Time complexity: O(n), where n is the length of the string. Each character is pushed and popped from the stack at most once.
        // Space complexity: O(n) in the worst case, due to the stack storing indices (up to n+1 elements if the string is all '(').
        stack<int>st;
        st.push(-1);
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    ans=max(ans,i-st.top());
                }
            }
        }
        return ans;
    }
};