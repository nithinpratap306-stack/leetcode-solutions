class Solution {
public:
    int maxScore(string s) {
        int on=0,ze=0;
        for(char c: s){
            if(c=='1') on++;
        }
        int mx=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0') ze++;
            else on--;
            mx=max(mx,ze+on);
        }
        return mx;
    }
};
/*Time Complexity: O(n)
Space Complexity: O(1)*/