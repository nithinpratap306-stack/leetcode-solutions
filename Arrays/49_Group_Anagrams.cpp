class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(string s:strs){
            string key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }
        for(auto [key,vec]:mp){
            ans.push_back(vec);
        }
        return ans;
    }
};
/*Time complexity: For N strings with average length L, each string is sorted once, costing O(L log L). Hash map insert/look-up is O(1) on average. Overall time is O(N * L log L).

Space complexity: For storing the input strings and the result, plus the hash map keys (sorted forms) and vectors of grouped strings. In total O(N * L) extra space in addition to the input, with the map overhead also contributing.*/