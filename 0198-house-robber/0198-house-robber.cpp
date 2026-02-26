class Solution {
public:
    int RobberHouse(int index,int n,vector<int>&nums,vector<int>&dp){
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        dp[index] = max(nums[index]+RobberHouse(index+2,n,nums,dp),RobberHouse(index+1,n,nums,dp));
        return dp[index];
    }
    int rob(vector<int>& nums) {
       vector<int>dp(nums.size()+2,-1);
       return RobberHouse(0,nums.size(),nums,dp); 
    }
};