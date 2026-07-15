class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int num=0;
        char sign='+';
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                num=10*num+(s[i]-'0');
            }
            if((!isdigit(s[i]) && s[i]!=' ')||i==s.size()-1){
                if(sign=='-'){
                    st.push(-num);
                }
                else if(sign=='+'){
                    st.push(num);
                }
                else if(sign=='*'){
                    num*=st.top();
                    st.pop();
                    st.push(num);
                }
                else if(sign=='/'){
                    num=st.top()/num;
                    st.pop();
                    st.push(num);
                }
                num=0;
                sign=s[i];
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};