class Solution {
public:
    int HouseRobber(int index,vector<int>&nums,vector<int>&dp){
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        dp[index] = max(HouseRobber(index+1,nums,dp),nums[index]+HouseRobber(index+2,nums,dp));
        return dp[index];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return HouseRobber(0,nums,dp);
    }
};