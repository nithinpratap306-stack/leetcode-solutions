class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        string mx="";
        for(int i=n-3;i>=0;i--){
            string s=num.substr(i,3);
            if(s[0]==s[1] && s[1]==s[2]) mx=max(mx,s);
        }
        return mx;
    }
};
/*	Complexity
⏱️ Time	O(n)
💾 Space	O(1)*/