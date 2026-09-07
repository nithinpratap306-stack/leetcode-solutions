class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>freq(n*n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freq[grid[i][j]]++;
            }
        }
        int miss=-1;
        int rep=-1;
        for(int i=1;i<=n*n;i++){
            if(freq[i]>1){
                rep=i;
            }
            if(freq[i]==0){
                miss=i;
            }
        }
        return {rep,miss};
    }
};
/*Time complexity: O(n^2)
- The grid is n x n, and we loop over all elements once to fill the frequency array.

Space complexity: O(n^2)
- The frequency array is size n^2 + 1 to count occurrences of values in the range [1, n^2].
*/