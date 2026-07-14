class Solution {
public:

// Time complexity: O(n), where n is the length of the input string. Each character is processed a constant number of times: building the pair array with a single pass, and then a single traversal that jumps between paired parentheses.

// Space complexity: O(n) for the pair array (size n) and the implicit stack used to collect opening parentheses (worst case up to n/2). The result string also uses up to O(n) space. Overall, O(n) auxiliary space.
    string reverseParentheses(string s) {
        string ans="";
        stack<int>st;
        vector<int>pair(s.size());
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);

            else if(s[i]==')'){
                int open=st.top();
                st.pop();

                pair[i]=open;
                pair[open]=i;
            }
        }
        int i=0;
        int direction=1;
        while(i<s.size()){
            if(s[i]=='(' || s[i]==')'){
                i=pair[i];

                direction*=-1;
            }
            else{
                ans+=s[i];
            }
            i+=direction;
        }
        return ans;
    }
};