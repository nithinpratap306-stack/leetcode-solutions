class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(string x: details){
            int age=(x[x.size()-4]-'0')*10+(x[x.size()-3]-'0');
            if(age>60) count++;
        }
        return count;
        
    }
};