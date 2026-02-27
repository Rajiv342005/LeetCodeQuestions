class Solution {
public:
    int CoinChange(int index,int size,int amount,vector<int>&coin,vector<vector<int>>&dp){
        if(amount==0) return 1;
        else if(amount<0 || index>=size) return 0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        dp[index][amount] = CoinChange(index,size,amount-coin[index],coin,dp)+CoinChange(index+1,size,amount,coin,dp);
        return dp[index][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));     
        return CoinChange(0,n,amount,coins,dp);
    }
};