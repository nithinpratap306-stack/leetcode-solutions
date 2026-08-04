class Solution {
public:
    bool parseBoolExpr(string expression) {
        // Time complexity: O(n), where n is the length of the expression. Each character is pushed or popped from the stack a constant number of times, and each closing parenthesis triggers a constant amount of work proportional to the number of literals inside that group, but overall each character is processed a constant number of times.
        // Space complexity: O(n) in the worst case, due to the explicit stack storing characters from the expression. In typical balanced expressions, the stack height is proportional to the nesting depth.
        stack<char>st;
        int t=0,f=0;
        for(char c: expression){
            if(c=='(' || c==',') continue;

            else if(c==')'){

                while(!st.empty() && (st.top()=='f'||st.top()=='t')){
                    if(st.top()=='f') f++;
                    else t++;
                    st.pop();
                }

                char op=st.top();
                st.pop();
                char to_push;
                
                if(op=='!'){
                    to_push=(t==1)? 'f':'t';
                }
                else if(op=='&'){
                    to_push=(f==0)? 't':'f';
                }
                else{
                    to_push=(t==0)? 'f':'t';
                }

                st.push(to_push);
                t=0;
                f=0;
            }

            else st.push(c);
        }
        if(st.top()=='t') return true;
        return false;
    }
};