//Marked as stack , but it only uses greedy algorithm 
class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int need=0;
        for(char c: s){
            if(c=='('){
                if(need%2==1){          //works in cases like '()(' . here the need is 1 , after the second char.
                    ans++;
                    need--;
                }
                need+=2;
            }
            else{
                need-=1;
                if(need==-1){          //works where the closing parantheses doesn't have any opening parantheses , like '))'.
                    need=1;
                    ans++;
                }
            }
        }
        return ans+need;
    }
};