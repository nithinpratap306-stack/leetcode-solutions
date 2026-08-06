class Solution {
public:
    int calculate(string s) {
    stack<long>st;
        long num=0;
        int sign=1;
        long ans=0;
        for(char c: s){
            if(isdigit(c)){
                num=num*10 + c-'0';
            }
            else if(c=='+'){
                ans+=sign*num;
                num=0;
                sign=1;
            }

            else if(c=='-'){
                ans+=sign*num;
                num=0;
                sign=-1;
            }

            else if(c=='('){
                st.push(ans);
                st.push(sign);
                ans=0;
                sign=1;
            }
            else if(c==')'){   
                ans+=sign*num;             
                int prevs=st.top();
                st.pop();
                long prev=st.top();
                st.pop();
                ans=prev+prevs*ans;
                num=0;
            }
        }
        ans+=sign*num;
        return ans;
    }
};
/*Time complexity: O(n), where n is the length of the input string. Each character is processed once, and stack operations are O(1).
Space complexity: O(h), where h is the maximum depth of nested parentheses (the maximum stack size). In the worst case, h can be O(n) for deeply nested expressions.*/