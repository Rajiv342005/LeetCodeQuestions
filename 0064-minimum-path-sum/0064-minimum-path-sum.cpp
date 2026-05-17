class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Space Optimization Approach..
        int m = grid.size();
        int n = grid[0].size();
        vector<int>dp(n+1,INT_MAX);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    dp[j] = grid[i][j];
                    continue;
                }
                int minpath = min(dp[j],dp[j+1]);
                dp[j] = minpath+grid[i][j];
            }
        }
        return dp[0];
    }
};