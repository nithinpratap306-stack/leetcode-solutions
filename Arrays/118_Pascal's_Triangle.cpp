class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            vector<int>vec(i,1);
            for(int j=1;j<i-1;j++){
                vec[j]=ans.back()[j-1]+ans.back()[j];
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
/*The function generates Pascal’s triangle up to numRows rows.

Time complexity:
- It builds each row i with i elements.
- Total number of elements created is 1 + 2 + ... + numRows = numRows*(numRows+1)/2.
- Each element is assigned in O(1) time, so total time is O(numRows^2).

Space complexity:
- It stores all rows in ans, which holds numRows*(numRows+1)/2 integers.
- Additional overhead is negligible, so space complexity is O(numRows^2).*/