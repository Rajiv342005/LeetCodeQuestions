class Solution {
public:
    int JumpGame(int index,vector<int>&nums,vector<int>&dp){
        if(index>=nums.size()) return 1;
        if(nums[index-1]==0) return 0;
        if(dp[index-1]!=-1) return dp[index-1];
        for(int i=1;i<=nums[index-1];i++){
            if(JumpGame(index+i,nums,dp)){
                if(JumpGame(index+i,nums,dp)){
                    dp[index-1] = 1;
                    return dp[index-1];
                }
            }
        }
        dp[index-1] = 0;
        return dp[index-1];
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return JumpGame(1,nums,dp);
        
    }
};