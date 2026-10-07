class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>low(26,0);
        vector<int>up(26,0);
        for(char c : s){
            if(islower(c)) low[c-'a']++;
            else up[c-'A']++;
        }
        int ans=0;
        bool odd=false;
        for(int i=0;i<26;i++){
            ans+=low[i]/2 * 2;
            ans+=up[i]/2 * 2;

            if(low[i]%2 || up[i]%2) odd=true;
        }
        return ans+(odd? 1:0);
    }
};
/*Time Complexity: O(n)
Space Complexity: O(1)*/