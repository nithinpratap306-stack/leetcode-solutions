class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Time complexity: O(amount * m), where m is the number of coin types. This is because for each amount from 1 to amount, we iterate over all m coins to update dp[a].
        // Space complexity: O(amount). The dp array stores a value for each sub-amount from 0 to amount.  

        int m=coins.size();
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int a=1;a<=amount;a++){
            for(int j=0;j<m;j++){
                if(coins[j]<=a && dp[a-coins[j]]!=INT_MAX){
                    dp[a]=min(dp[a],dp[a-coins[j]]+1);
                }
             }
        }
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};