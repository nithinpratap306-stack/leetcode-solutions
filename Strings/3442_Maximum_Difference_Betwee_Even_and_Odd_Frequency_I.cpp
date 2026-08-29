class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26,0);
        int odd=INT_MIN;
        int even=INT_MAX;
        for(char c : s){
            freq[c-'a']++;
        }
        for(int f: freq){
            if(f==0) continue;
            if(f%2==0){
                even=min(even,f);
            }
            else odd=max(odd,f);
        }
        return odd-even;
    }
};