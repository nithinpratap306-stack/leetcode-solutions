class Solution {
public:
    bool isValid(string s) {
        vector<char>st;
        for(char c: s){
            if(c=='('||c=='{'||c=='[') st.push_back(c);
            else{
                if(st.empty()) return false;
                if((c==')' && st.back()!='(') || (c=='}' && st.back()!='{') || (c==']' && st.back()!='[')){
                    return false;
                }
                else st.pop_back();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
/*Time complexity: O(n), where n is the length of the string. Each character is pushed or popped from the stack at most once.

Space complexity: O(n) in the worst case, due to the stack storing up to n opening brackets.*/