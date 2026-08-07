class Solution {
public:
    vector<int> fnse(vector<int>nums){
        vector<int>nse(nums.size(),nums.size());
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(!st.empty())nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> fpse(vector<int>nums){
        vector<int>pse(nums.size(),-1);
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty())pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    int maxSumMinProduct(vector<int>& nums) {
        vector<int>nse=fnse(nums);
        vector<int>pse=fpse(nums);
        vector<long>prefix(nums.size()+1,0);
        long sm=0;
        for(int i=0;i<nums.size();i++){
            prefix[i]=sm;
            sm+=nums[i];
        }
        prefix[nums.size()]=sm;

        long mx=-1;
        const int mod=1e9 + 7;
        for(int i=0;i<nums.size();i++){
            long ans=(( prefix[nse[i]]-prefix[pse[i]+1] )* nums[i]); 
            mx=max(ans,mx);
        }
        return mx%mod;
    }
};
/*The algorithm uses monotonic stacks to find next smaller element on the left (pse) and next smaller element on the right (nse) for each index, then computes a range sum times the element.

Time complexity:
- Building nse and pse with two passes each: O(n) time.
- Computing prefix sums: O(n).
- Final scan to compute the max: O(n).
Total time: O(n).

Space complexity:
- nse and pse arrays: O(n) space.
- prefix array: O(n) space.
- Stack usage: O(n) in the worst case.
Total auxiliary space: O(n).*/