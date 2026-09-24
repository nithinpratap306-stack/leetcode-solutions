class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>mp(26,0);
        for(char c: magazine){
            mp[c-'a']++;
        }
        for(char c: ransomNote){
            mp[c-'a']--;
            if(mp[c-'a']<0){
                return false;
            }
        }
        return true;
    }
};
/*Time complexity: O(m + n), where m is the length of magazine and n is the length of ransomNote. Each string is traversed once to build and check counts.
Space complexity: O(1), specifically O(26) for the fixed-size frequency array, independent of input sizes.*/