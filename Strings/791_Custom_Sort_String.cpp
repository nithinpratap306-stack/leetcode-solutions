class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>freq(26,0);
        for(char c : s){
            freq[c-'a']++;
        }
        string ans="";
        for(char c: order){
            while(freq[c-'a']>0){
                ans+=c;
                freq[c-'a']--;
            }
        }

        for(char c: s){
            while(freq[c-'a']>0){
                ans+=c;
                freq[c-'a']--;
            }
        }
        return ans;
    }
};
/*Time complexity: O(n + m + k), where n is the length of s and m is the length of order. We count frequencies in O(n).
Then we append each character of s at most once per occurrence in order (loop over order with total appends up to n) and the remaining characters also total up to n.
Overall linear in the combined lengths; effectively O(n + m).

Space complexity: O(1) additional space aside from the 26-size frequency array and the output string.
The freq array is constant size, and the output is of length n, so auxiliary space is O(1).*/