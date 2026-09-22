class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>mp;
        for(char c: allowed){
            mp[c]++;
        }
        int count=0;
        for(string s: words){
            count++;
            for(char c: s){
                if(mp[c]==0){
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};
/*Time complexity: O(sum of lengths of all words + length of allowed). For each word we scan its characters until a mismatch is found; in the worst case we traverse all characters in all words. Building the map takes O(len(allowed)).
Space complexity: O(1) auxiliary space aside from the frequency map, which stores up to 26 entries for lowercase English letters, so effectively O(1). If counting the map as part of space, it's O(26) = O(1).*/