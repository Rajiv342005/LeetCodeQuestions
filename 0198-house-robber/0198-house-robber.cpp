class Solution {
public:
    // int RobberHouse(int index,int n,vector<int>&nums,vector<int>&dp){
    //     if(index>=n) return 0;
    //     if(dp[index]!=-1) return dp[index];
    //     dp[index] = max(nums[index]+RobberHouse(index+2,n,nums,dp),RobberHouse(index+1,n,nums,dp));
    //     return dp[index];
    // }
    int rob(vector<int>& nums) {
        //MethodNo-1(Bottom-up Approach)
    //    vector<int>dp(nums.size()+2,-1);
    //    return RobberHouse(0,nums.size(),nums,dp); 
       // MethodNo-2(Space Optimization Approach)
       int firstHouse =0;
       int secondHouse =0;
       int final;
       for(int i=nums.size()-1;i>=0;i--){
        final = max(nums[i]+secondHouse,firstHouse);
        secondHouse = firstHouse;
        firstHouse = final;
       }
       return final;
    }
};