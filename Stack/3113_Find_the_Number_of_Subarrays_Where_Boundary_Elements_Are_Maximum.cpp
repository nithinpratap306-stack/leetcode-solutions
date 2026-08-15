class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        stack<pair<int,int>>st;
        long long ans=0;
        for(int i: nums){
            while(!st.empty() && st.top().first<i){
                st.pop();
            }
            if(!st.empty() && st.top().first==i){
                ans+=st.top().second;
                st.top().second++;
            }
            else st.push({i,1});
            ans++;
        }
        return ans;
    }
};
/*Time complexity: O(n) since each element is pushed once and popped at most once from the stack, plus constant work per element.
Space complexity: O(m) where m is the number of distinct values stored on the stack at any time (in the worst case it can be O(n) if all elements are unique and the stack grows).*/