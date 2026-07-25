class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int>cnt(heights.size(),0);
        int n=heights.size();
        
        //brute force
        // for(int i=0;i<n-1;i++){
        //     int mx=heights[i+1];
        //     for(int j=i+1;j<n;j++){
        //         if(heights[j]>heights[i]){
        //             cnt[i]++;
        //             break;
        //         }
        //         if((j-1)!=i && (j-1)!=-1 && mx>heights[j]){
        //             continue;
        //         }
        //         cnt[i]++;
        //         mx=heights[j];
        //     }
        // }

        //Optimal - stack based
        // Time complexity: O(n). Each element is pushed onto the stack once and popped at most once, plus a constant amount of work per element.
        // Space complexity: O(n) in the worst case for the stack, since in the worst case the stack can contain all elements. The resulting count array uses O(n) as well.
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<heights[i]){
                st.pop();
                cnt[i]++;
            }
            if(!st.empty())cnt[i]++;
            st.push(heights[i]);
        }
        return cnt;
    }
};