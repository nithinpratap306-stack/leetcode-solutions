class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >pq;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!pq.empty() && pq.top().first<nums[i]){
                int ind=pq.top().second;
                pq.pop();
                ans[ind]=nums[i];
            }

            while(!st.empty() && nums[i]>nums[st.top()]){
                int ind=st.top();
                st.pop();
                pq.push({nums[ind],ind});
            }
            st.push(i);
        }
        return ans;
    }
};
/*Time complexity: O(n log n). Each element is pushed and popped from the stack at most once, and each push to the priority queue occurs at most once per element when it becomes the next greater for some earlier index; each heap operation is O(log n). Overall, number of heap operations is O(n), giving O(n log n).
Space complexity: O(n). We store the result vector of size n, the stack can hold up to n indices, and the priority queue can hold up to n elements in the worst case.*/