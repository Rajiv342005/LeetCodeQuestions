class Solution {
public:
    int MinimumCost(int n,vector<int>&dp){
        if(n<=1) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans = INT_MAX;
        for(int i=1;i<n;i++){
            int cost = i*(n-i) +MinimumCost(i,dp)+MinimumCost(n-i,dp);
            ans = min(ans,cost);
        }
        return dp[n] = ans;
    }
    int minCost(int n) {
        vector<int>dp(n+1,-1);
        return MinimumCost(n,dp);
    }
};