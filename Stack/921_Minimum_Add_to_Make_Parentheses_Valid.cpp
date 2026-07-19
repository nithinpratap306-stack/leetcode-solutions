class Solution {
public:
// Time complexity: O(n), where n is the length of the string. Each character is pushed or popped at most once.
// Space complexity: O(n) in the worst case, due to the stack potentially holding all opening parentheses.
    int minAddToMakeValid(string s) {
        stack<char>op;
        int count=0;
        for(char c:s){
            if(c=='('){
                op.push(c);
            }
            else{
                if(op.empty()){
                    count++;
                }
                else{
                    op.pop();
                }
            }
        }
        return count+op.size();
    }
};