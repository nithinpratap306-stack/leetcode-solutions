class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>vec;
        int n=position.size();
        for(int i=0;i<n;i++){
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(),vec.end());
        stack<float>st;
        for(int i=n-1;i>=0;i--){
            float time=1.0*(target-vec[i].first)/vec[i].second;
            if(st.empty()) st.push(time);
            else if(time>st.top()) st.push(time);
        }
        return st.size();
    }
};
/*Time complexity: O(n log n) due to sorting the vector of pairs by position. The subsequent single reverse pass with a stack is O(n). Overall O(n log n).
Space complexity: O(n) for the vec vector and the stack in the worst case. The vector stores n pairs and the stack can hold up to n times in the worst scenario.
*/