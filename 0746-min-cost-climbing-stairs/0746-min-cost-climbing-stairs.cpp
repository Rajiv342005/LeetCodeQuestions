class Solution {
public:
    int ClimbingStair(int index,vector<int>&costs,vector<int>&dp){
        if(index>=costs.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        dp[index] =  min(ClimbingStair(index+1,costs,dp)+costs[index],costs[index]+ClimbingStair(index+2,costs,dp));
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& costs) {
        vector<int>dp(costs.size(),-1);
        int index0 = ClimbingStair(0,costs,dp);
        int index1 = ClimbingStair(1,costs,dp);
        return min(index0,index1);
    }
};