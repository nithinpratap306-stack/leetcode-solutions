class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count=0;
        vector<int>sorted=heights;
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<heights.size();i++){
            if(sorted[i]!=heights[i]){
                count++;
            }
        }
        return count;
    }
};
/*Time complexity: O(n log n) due to sorting the copy of the array. The subsequent pass is O(n), but dominated by the sort.
Space complexity: O(n) extra space for the copied vector sorted, in addition to the input array. The sort operates in-place on the copy, so overall auxiliary space is O(n).*/