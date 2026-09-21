class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>row;
        for(int i=0;i<=rowIndex;i++){
            row.push_back(1);
            for(int j=i-1;j>=1;j--){
                row[j]=row[j-1]+row[j];
            }
        }
        return row;
    }
};
/*The function builds a row of Pascal's triangle up to rowIndex, returning only that final row.
Time complexity:
- Outer loop runs i from 0 to rowIndex, total rowIndex + 1 iterations.
- Inner loop runs roughly i-1 times on iteration i, so total work is sum_{i=0}^{rowIndex} (i-1) ≈ O(rowIndex^2).
- Overall time complexity is O(rowIndex^2).
Space complexity:
- It stores a single row vector of size rowIndex + 1.
- Additional space is O(1) besides the output, so overall space complexity is O(rowIndex).*/