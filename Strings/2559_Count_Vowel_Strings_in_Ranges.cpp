class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ans(queries.size());
        vector<int>prefix(words.size()+1,0);
        int sum=0;
        int ind=0;
        string vowel="aeiou";
        for(const string& s: words){
            if(vowel.find(s[0])!=string::npos && vowel.find(s[s.size()-1])!=string::npos){
                sum++;
            }
            ind+=1;
            prefix[ind]=sum;
        }
        ind=-1;
        int vow=0;
        for(auto& q: queries){
            vow=prefix[q[1]+1]-prefix[q[0]];
            ind+=1;
            ans[ind]=vow;
        }
        return ans;
    }
};
/*Time complexity:
- Building the prefix array iterates over all words once: O(n), where n is words.size().
- Each query is answered in O(1) using the prefix differences: O(m), where m is queries.size().
- Total time complexity: O(n + m).

Space complexity:
- The prefix array uses O(n) extra space.
- The result vector uses O(m) space.
- Overall space complexity: O(n + m).*/