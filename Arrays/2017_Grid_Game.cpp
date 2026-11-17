class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();

        long long top=0;
        for(int i=0;i<n;i++){
            top+=grid[0][i];
        }

        long long ans=LLONG_MAX;
        long long bottomPrefix=0;

        for(int j=0;j<n;j++){
            top-=grid[0][j];
            long long robot2=max(top,bottomPrefix);
            ans=min(ans,robot2);
            bottomPrefix+=grid[1][j];
        }
        return ans;
    }
};
/*Time complexity: O(n), where n is the number of columns. Each cell is processed a constant number of times as we compute the initial top sum and then a single pass updating top and bottomPrefix.
Space complexity: O(1), aside from the input grid, since we only use a few scalar variables (top, bottomPrefix, ans, n).*/