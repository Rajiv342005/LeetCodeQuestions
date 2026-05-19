class Solution {
public:
    int Tribonacci(int n,vector<int>&dp){
        if(n<3){
            if(n==0) return 0;
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        dp[n] = Tribonacci(n-1,dp)+Tribonacci(n-2,dp)+Tribonacci(n-3,dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return Tribonacci(n,dp);
    }
};