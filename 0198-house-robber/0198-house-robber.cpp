class Solution {
public:
    int HouseRobber(int index,vector<int>&nums,vector<int>&dp){
        if(dp[index]!=-1) return dp[index];
        if(index>=nums.size()) return 0;
        dp[index] = max(HouseRobber(index+1,nums,dp),nums[index]+HouseRobber(index+2,nums,dp));
        return dp[index];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+2,-1);
        return HouseRobber(0,nums,dp);
    }
};