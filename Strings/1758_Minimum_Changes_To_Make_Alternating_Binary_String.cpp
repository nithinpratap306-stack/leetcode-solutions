class Solution {
public:
    int minOperations(string s) {
        int cnt1=0,cnt2=0;
        for(int i=0;i<s.size();i++){
            char exp1=(i%2==0)? '1': '0';
            char exp2=(i%2==0)? '0': '1';

            if(s[i]!=exp1) cnt1++; 
            if(s[i]!=exp2) cnt2++; 
        }
        
        return min(cnt1,cnt2);
    }
};
/*Time Complexity: O(n)
Space Complexity: O(1)*/