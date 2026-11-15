class Solution {
public:
    int minSwaps(string s) {
        int close=0,max_close=0;
        for(char c: s){
            if(c=='[') close--;
            else close++;
            max_close=max(close,max_close);
        }
        
        return (max_close+1)/2;
    }
};
/*Time complexity: O(n), where n is the length of the string. Each character is pushed or popped from the stack at most once.

Space complexity: O(n) in the worst case, due to the stack storing up to n opening brackets.*/