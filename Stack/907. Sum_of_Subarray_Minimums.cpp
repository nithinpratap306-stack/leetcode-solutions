class Solution {
public:
// - Time complexity: O(n). Each of the functions findnse and findpse processes the array once with amortized O(1) per element due to stack operations, and the final loop is O(n). Overall O(n).
// - Space complexity: O(n). Additional space for the two auxiliary arrays nse and pse (each of size n) plus the stack usage, which in worst case is O(n).
    vector<int> findnse(const vector<int>&arr){
        stack<int>st;
        vector<int>nse(arr.size(),arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findpse(const vector<int>&arr){
        stack<int>st;
        vector<int>pse(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()) pse[i]=st.top();

            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse=findnse(arr);
        vector<int>pse=findpse(arr);
        long long total=0;
        const int mod=1e9 + 7;
        for(int i=0;i<arr.size();i++){
            long long comb =1ll * ( i - pse[i] ) * ( nse[i] - i );
            long long contribution = comb*arr[i];
            total = (total + contribution % mod ) % mod;
        }
        return total;
    }
};