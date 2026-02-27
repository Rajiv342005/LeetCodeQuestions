class Solution {
public:
    int RobberHouseII(int index,int n,vector<int>&nums,vector<int>&dp){
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        dp[index] = max(RobberHouseII(index+1,n,nums,dp),nums[index]+RobberHouseII(index+2,n,nums,dp));
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(RobberHouseII(0,n-1,nums,dp1),RobberHouseII(1,n,nums,dp2));
    }
};