class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>freq(26,0);
        for(string s: words){
            for(char c: s){
                freq[c-'a']++;
            }
        }
        for(int i: freq){
            if(i==0) continue;
            if(i%words.size()!=0) return false;
        }
        return true;
    }
};
/*Time Complexity: O(N) where N = total number of characters across all words
Space Complexity: O(1) — fixed 26-element array*/