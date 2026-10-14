class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>freq(26,0);
        vector<int>curr(26,0);
        vector<string>ans;
        int i=0;
        for(string s: words){
            if(i==0){
                for(char c: s){
                    freq[c-'a']++;
                }
                i=1;
            }
            else{    
                fill(curr.begin(),curr.end(),0);
                for(char c: s){
                    curr[c-'a']++;
                }
                for(int i=0;i<26;i++){
                    freq[i]=min(freq[i],curr[i]);
                }
            }
            
        }
        for(char c: words[0]){
            if(freq[c-'a']>=1){
                ans.push_back(string(1,c));
                freq[c-'a']--;
            }
        }
        return ans;
    }
};
/*Time: O(N+m), where (N) is the total number of characters and (m) is the number of words.
Auxiliary space: O(1), excluding the output.*/