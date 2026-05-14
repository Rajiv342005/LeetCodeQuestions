class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                int accept = INT_MAX;
                if(coins[i]<=j && dp[j-coins[i]]!=INT_MAX){
                    accept = 1+dp[j-coins[i]];
                }
                dp[j] = min(accept,dp[j]);
            }
        }
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};