class Solution {
public:
    int minCostClimbingStairs(vector<int>& costs) {
        // vector<int>dp(costs.size()+1,0);
        // for(int i=2;i<dp.size();i++){
        //     dp[i] = min(dp[i-1]+costs[i-1],dp[i-2]+costs[i-2]);
        // }
        // return dp.back(); 
        int firstpos =0;
        int secondpos =0;
        for(int i=2;i<=costs.size();i++){
            int temp = secondpos;
            secondpos = min(firstpos+costs[i-2],secondpos+costs[i-1]);
            firstpos = temp;
        }
        return secondpos;     
    }
};