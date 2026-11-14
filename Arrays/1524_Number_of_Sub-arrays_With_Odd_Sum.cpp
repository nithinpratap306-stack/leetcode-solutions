class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans=0,even=1,odd=0,prefix=0;
        int mod=1e9 + 7;
        for(int i: arr){
            prefix+=i;
            if(prefix%2){
                ans+=even;
                odd++;
            }
            else{
                ans+=odd;
                even++;
            }
            ans%=mod;
        }
        return ans;
    }
};
/*Time complexity: O(n), where n is the length of arr. Each element is processed once.

Space complexity: O(1) extra space. Only a fixed number of integer variables (ans, even, odd, prefix, mod) are used, regardless of input size.*/