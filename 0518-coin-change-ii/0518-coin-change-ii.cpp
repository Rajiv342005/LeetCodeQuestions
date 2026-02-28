class Solution {
public:
    int Totalways(int index,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(index==0) return 0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        if(amount<coins[index-1]) return dp[index][amount] = Totalways(index-1,amount,coins,dp);
        return dp[index][amount] = Totalways(index,amount-coins[index-1],coins,dp)+Totalways(index-1,amount,coins,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return Totalways(n,amount,coins,dp);   
    }
};