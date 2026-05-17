class Solution {
public:
    int minstep(int index,vector<int>&nums,vector<int>&dp){
        if(index>=nums.size()-1) return 0;
        if(nums[index]==0) return INT_MAX;
        if(dp[index]!=-1) return dp[index];
        int minimumstep = INT_MAX;
        for(int i=1;i<=nums[index];i++){
            int step = minstep(i+index,nums,dp);
            if(step!=INT_MAX)
            minimumstep = min(minimumstep,step+1);
        }
        return dp[index]= minimumstep;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return minstep(0,nums,dp);
    }
};