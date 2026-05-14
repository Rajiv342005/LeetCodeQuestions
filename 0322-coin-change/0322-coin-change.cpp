class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX));
        for(int i=0;i<=n;i++){
            dp[i][0]  = 0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                int accept = INT_MAX;
                if(coins[i]<=j && dp[i][j-coins[i]]!=INT_MAX){
                    accept = 1+dp[i][j-coins[i]];
                }
                int reject = dp[i+1][j];
                dp[i][j] = min(accept,reject);
            }
        }
        if(dp[0][amount]==INT_MAX) return -1;
        return dp[0][amount];
    }
};