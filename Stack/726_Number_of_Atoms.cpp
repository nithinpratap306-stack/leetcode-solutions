class Solution {
public:
    string countOfAtoms(string formula) {
        // Time complexity: O(n), where n is the length of the formula. Each character is processed a constant number of times (opening/closing parentheses, element names, and numeric multipliers). Each map entry is visited a limited number of times when merging after a parenthesis closes.
        // Space complexity: O(m), where m is the number of distinct atoms in the formula (the size of the stack of maps and the resulting map). In practice, the stack holds at most depth of parentheses, and each map stores counts for distinct element names encountered. The final output string length is also proportional to the number of distinct elements and their counts.
        stack<map<string,int>>st;
        int i=0;
        st.push({});
        while(i<formula.size()){
            if(formula[i]=='('){
                st.push({});
                i++;
            }
            else if(formula[i]==')'){
                int mul=0;
                i++;
                while(i<formula.size() && isdigit(formula[i])){
                    mul=mul*10+(formula[i]-'0');
                    i++;
                }
                auto curr=st.top();
                st.pop();
                if(mul==0) mul=1;
                for(auto [key,val] : curr){
                    st.top()[key]+=val*mul;
                }
            }
            else{
                string ans="";
                ans+=formula[i];
                i++;
                while( i<formula.size() && islower(formula[i])){
                    ans+=formula[i];
                    i++;
                }
                int count=0;
                while(i<formula.size() && isdigit(formula[i])){
                    count=count*10+(formula[i]-'0');
                    i++;
                }
                if(count==0) count=1;
                st.top()[ans]+=count;
            }
        }
        string fans="";
        for(auto [key,val] : st.top()){
            fans+=key;
            if(val>1) fans+=to_string(val);
        }
        return fans;
    }
};