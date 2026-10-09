class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>mp(26,-1);
        int sub=-1;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]-'a']!=-1){
                sub=max(sub,i-mp[s[i]-'a']-1);
                continue;
            }
            mp[s[i]-'a']=i;
        }
        return sub;
    }
};
/*Time Complexity: O(n)
Space Complexity: O(1) — fixed array of 26 elements.*/