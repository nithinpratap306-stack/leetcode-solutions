class Solution {
public:
// Time complexity: O(n), where n is the length of the string. Each character is pushed/popped from one of the two stacks at most once, and the final pass pops at most min(number of '(' , number of '*').
// Space complexity: O(n) in the worst case, due to the two stacks that can store up to n elements combined (e.g., a string of only '(' or only '*' before matching).
    bool checkValidString(string s) {
        stack<char>st;
        stack<char>star;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);
            }
            else{
                if(st.empty() && star.empty()) return false;
                (st.empty())?star.pop():st.pop();
            }
        }
        while(!st.empty() && !star.empty()){
            if(st.top()>star.top()){
                return false;
            }
            st.pop();
            star.pop();
        }
        return(st.empty());
    }
};