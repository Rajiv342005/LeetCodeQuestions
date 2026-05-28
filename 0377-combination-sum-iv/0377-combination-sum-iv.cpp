class Solution {
public:
    int CombinationIV(int index,vector<int>&nums,int sum,int target,vector<int>&dp){
        if(sum==target){
            return 1;
        }
        if(sum>target || index>=nums.size()) return 0;
        if(dp[sum]!=-1) return dp[sum];
        int ways =0;
        for(int i=0;i<nums.size();i++){
            ways+=CombinationIV(i,nums,sum+nums[i],target,dp);
        }
        return dp[sum] = ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int sum =0;
        vector<int>dp(target+1,-1);
        return CombinationIV(0,nums,sum,target,dp);
    }
};