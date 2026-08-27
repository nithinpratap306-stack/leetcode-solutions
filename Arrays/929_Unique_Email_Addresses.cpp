class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>st;
        for(string email: emails){
            string normalized;
            int i=0;
            while(i<email.size() && email[i]!='@'){
                if(email[i]=='.'){
                    i++;
                    continue;
                }
                else if(!normalized.empty() && normalized.back()=='+'){
                    i++;
                    continue;
                }
                else{
                    normalized.push_back(email[i]);
                }
                i++;
            }
            if(normalized.back()=='+') normalized.pop_back();

            normalized.push_back('@');
            normalized+=email.substr(i+1,email.size()-i-1);
            st.insert(normalized);
        }
        return st.size();
    }
};