class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // Time complexity: O(n log n) due to sorting of indices by positions. The subsequent pass processes each robot at most a constant number of times in the while loops, but in the worst case each collision reduces either the current or the top robot’s health, leading to amortized O(n) additional operations overall. Overall, O(n log n) time due to sorting dominates.
    // Space complexity: O(n) extra space for the ids vector and the stack, plus the output vector. The stack holds at most n indices, and ids holds n indices, so O(n) auxiliary space. The output vector is also O(n) in the worst case.
        stack<int>st;
        int n=positions.size();
        vector<int>ids;
        for(int i=0;i<n;i++){
            ids.push_back(i);
        }
        auto compare=[&](int id1,int id2){
            return positions[id1]<=positions[id2];
        };
        sort(ids.begin(),ids.end(),compare);

        for(int i: ids){
            if(directions[i]=='R') st.push(i);
            else{
                while(!st.empty() && healths[i]!=0){
                    if(healths[i]>healths[st.top()]){
                        healths[i]--;
                        healths[st.top()]=0;
                        st.pop();
                    }
                    else if(healths[i]<healths[st.top()]){
                        healths[i]=0;
                        healths[st.top()]--;
                    }
                    else{
                        healths[i]=0;
                        healths[st.top()]=0;
                        st.pop();
                    }
                }
            }
        }
        vector<int>h;
        for(int i: healths){
            if(i!=0) h.push_back(i);
        }
        return h;
    }
};