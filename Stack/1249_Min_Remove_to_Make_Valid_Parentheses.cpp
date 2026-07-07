class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        vector<bool>remove(s.size(),false);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    remove[i]=true;
                }
                else st.pop();
            }
        }
        string ans="";
        while(!st.empty()){
            remove[st.top()]=true;
            st.pop();
        }
        for(int i=0;i<s.size();i++){
            if(!remove[i]){
                ans+=s[i];
            }
        }
        return ans;
    }
};