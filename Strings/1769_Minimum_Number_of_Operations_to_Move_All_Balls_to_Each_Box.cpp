class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.size(),0);
        int balls=0;
        int ops=0;
        for(int i=0;i<boxes.size();i++){
            ops+=balls;
            ans[i]+=ops;
            if(boxes[i]=='1') balls++;
        }
        balls=0;
        ops=0;
        for(int i=boxes.size()-1;i>=0;i--){
            ops+=balls;
            ans[i]+=ops;
            if(boxes[i]=='1') balls++;
        }
        return ans;
    }
};
/*Time complexity: O(n), where n is the length of the boxes string. The algorithm makes two linear passes over the string.
Space complexity: O(1) beyond the output array. It uses a few integer variables and the result vector of size n, so auxiliary space is O(1).*/