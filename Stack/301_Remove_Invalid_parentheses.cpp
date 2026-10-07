class Solution {
public: 
    unordered_set<string>res;
    void dfs(string &s, int index, int rightrem, int leftrem, int bal, string curr){
        if(index==s.size()){
            if(rightrem==0 && leftrem==0 && bal==0) res.insert(curr);
            return;
        }
        char c=s[index];
        if(c=='(' && leftrem>0) dfs(s, index+1, rightrem, leftrem-1, bal, curr);
        if(c=='(') dfs(s,index+1,rightrem,leftrem,bal+1,curr+c);

        if(c==')' && rightrem>0) dfs(s, index+1, rightrem-1, leftrem , bal, curr);
        if(c==')' && bal>0) dfs(s, index+1, rightrem, leftrem, bal-1, curr+c);

        if(isalpha(c)) dfs(s, index+1, rightrem, leftrem, bal, curr+c);
    }
    vector<string> removeInvalidParentheses(string s) {
        res.clear();    
        int bal=0;
        int rightrem=0,leftrem=0;
        for(char c: s){
            if(c=='(') bal++;
            else if(c==')'){
                if(bal>0) bal--;
                else rightrem++;
            }
        }
        leftrem=bal;
        dfs(s,0,rightrem,leftrem,0,"");
        vector<string>ans(res.begin(),res.end());
        return ans;
    }
};
/*Time: O(2^n · n) worst-case, including constructing strings / storing results.
Space: O(2^n · n) in the worst case for the output/result set, plus O(n) recursion depth.*/