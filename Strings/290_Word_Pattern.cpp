class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string>words;
        while(ss>>word){
            words.push_back(word);
        }
        if(words.size()!=pattern.size()) return false;
        unordered_map<char,string>mp;
        unordered_map<string,char>sp;
        for(int i=0;i<pattern.size();i++){
            string w=words[i];
            char c=pattern[i];
            if(mp.find(c)!=mp.end()){
                if(mp[c]!=w){
                    return false;
                }
            }
            else{
                mp[c]=w;
            }
            if(sp.find(w)!=sp.end()){
                if(sp[w]!=c){
                    return false;
                }
            }
            else{
                sp[w]=c;
            }
        }
        return true;
    }
};
/*Time complexity: O(n), where n is the length of the pattern (and number of words in s after splitting). Each character/word is processed once, and map lookups/insertions are average O(1).
Space complexity: O(k), where k is the number of distinct pattern characters (and distinct words). In the worst case, you store up to min(n, alphabet size) entries in both maps, plus the list of words. Overall auxiliary space is O(k).*/