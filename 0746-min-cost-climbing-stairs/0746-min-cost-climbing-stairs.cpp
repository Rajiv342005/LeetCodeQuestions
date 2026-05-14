class Solution {
public:
    int minCostClimbingStairs(vector<int>& costs) {
        vector<int>dp(costs.size()+1,0);
        for(int i=2;i<dp.size();i++){
            dp[i] = min(dp[i-1]+costs[i-1],dp[i-2]+costs[i-2]);
        }
        return dp.back();        
    }
};