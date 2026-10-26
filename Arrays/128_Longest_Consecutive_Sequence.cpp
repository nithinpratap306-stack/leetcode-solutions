class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int>st;
        for(int i: nums){
            st.insert(i);
        }
        int mx=1;
        int cnt=1;
        for(int i: st){
            if(st.find(i-1)!=st.end()) continue;
            else{
                cnt=1;
                while(true){
                    if(st.find(i+1)!=st.end()){
                        cnt++;
                        i++;
                    }
                    else break;
                }
            }
            mx=max(cnt,mx);
        }
        return mx;
    }
};
/*Time complexity: O(n) on average. Each element is inserted into the unordered_set once, and the inner while loop traverses each consecutive element at most once overall because it only starts from a left boundary (i where i-1 is not in the set) and then increments through the consecutive run. 
In the worst case with many separate runs, the total number of increments across all iterations is bounded by n. 
Therefore average time is linear.
Space complexity: O(n) for the unordered_set storing all distinct numbers. The additional variables use O(1) extra space.*/