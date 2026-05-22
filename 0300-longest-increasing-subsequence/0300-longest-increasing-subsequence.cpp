class Solution {
public:
    // int lis = INT_MIN;
    int LIS(int index1,int index2,vector<int>&nums,vector<vector<int>>&dp){
        if(index2>=nums.size()) return 0;
        if(dp[index1+1][index2]!=-1) return dp[index1+1][index2];

        int skip = LIS(index1,index2+1,nums,dp);

        int take =0;
        if(index1==-1 || nums[index1]<nums[index2]){
            take = 1+LIS(index2,index2+1,nums,dp);
        }
        return dp[index1+1][index2] =  max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        vector<vector<int>>dp(m+1,vector<int>(m,-1));
        return LIS(-1,0,nums,dp);
    }
};