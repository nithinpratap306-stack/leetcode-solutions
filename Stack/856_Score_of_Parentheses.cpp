class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int score=0;
        for(char c: s){
            if(c=='('){
                st.push(score);
                score=0;
            }
            else{
                score=st.top()+max(score*2,1);
                st.pop();
            }
        }
        return score;
    }
};
/*Time Complexity: O(n)
Space Complexity: O(n) — stack can hold up to n/2 opening parentheses.*/