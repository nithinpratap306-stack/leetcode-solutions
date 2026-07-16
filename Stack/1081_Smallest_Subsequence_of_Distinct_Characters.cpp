class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        vector<bool>instack(26,0);
        vector<int>freq(26,0);
        string ans="";

        for(char c:s ){=
            freq[c-'a']++;
        }
        for(char c: s){
            freq[c-'a']--;
            if(instack[c-'a']) continue;
            while(!st.empty() && st.top()>c && freq[st.top()-'a']>0){
                instack[st.top()-'a']=false;
                st.pop();
            }
            st.push(c);
            instack[c-'a']=true;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};