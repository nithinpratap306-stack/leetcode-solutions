class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>freq(26,0);
        for(char c: chars){
            freq[c-'a']++;
        }
        int ans=0;
        for(string s: words){
            vector<int>have(26,0);
            bool pos=true;
            for(char c: s){
                have[c-'a']++;
                if(have[c-'a']>freq[c-'a']){
                    pos=false;
                    break;
                }
            }
            if(pos){
                ans+=s.size();
            }
        }
        return ans;
    }
};
/*The function counts total length of words that can be formed from the given chars.

- Preprocessing freq for chars: O(|chars|) time and O(26) space.
- For each word s in words:
  - It builds a local have vector (size 26) and iterates over the characters of s once until it may early break. In the worst case, it inspects every character of s.
  - Overall per word: O(|s|) time and O(26) extra space (besides input).

Total time complexity: O(sum of lengths of all words + |chars|) which is O(N * L) in the worst-case where N is number of words and L is average word length (more precisely O(sum|s|) + O(|chars|)).

Total space complexity: O(26) for freq plus O(26) for have per word, i.e., O(1) auxiliary space. The input words and chars occupy their own space outside the algorithm.*/