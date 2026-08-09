class Solution {
public:
    vector<int> fnse(vector<int>strength){
        stack<int>st;
        vector<int>nse(strength.size(),strength.size());
        for(int i=strength.size()-1;i>=0;i--){
            while(!st.empty() && strength[st.top()]>strength[i]){
                st.pop();
            }
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> fpse(vector<int>strength){
        stack<int>st;
        vector<int>pse(strength.size(),-1);
        for(int i=0;i<strength.size();i++){
            while(!st.empty() && strength[st.top()]>=strength[i]){
                st.pop();
            }
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    int totalStrength(vector<int>& strength) {
        long long ans=0;
        int n=strength.size();
        vector<int>nse=fnse(strength);
        vector<int>pse=fpse(strength);
        
        const long long mod=1e9+7;
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++)
        {   
            prefix[i+1]=prefix[i]+strength[i];
        }
        
        vector<long long>preprefix(n+2,0);
        for(int i=0;i<=n;i++){
            preprefix[i+1]=(preprefix[i]+prefix[i]) % mod;
        }

        for(int i=0;i<n;i++){
            ans+=( ( (preprefix[nse[i]+1]-preprefix[i+1])*(i-pse[i])%mod  -  (preprefix[i+1]-preprefix[pse[i]+1])*(nse[i]-i)%mod ) * strength[i] ) % mod;
            ans=(ans%mod + mod)%mod;
        }
        return ans % mod;
    }

};
/*Time complexity:
- Calculating nse and pse uses single passes with a stack each: O(n) time.
- Building prefix and preprefix arrays are both O(n).
- The final loop iterates n times with O(1) work per iteration.
Overall, the time complexity is O(n).

Space complexity:
- nse and pse store indices: O(n) space.
- prefix and preprefix store cumulative sums: O(n) space each, totaling O(n) additional space.
- Stack usage at most O(n) in worst case.
Overall, the space complexity is O(n).*/