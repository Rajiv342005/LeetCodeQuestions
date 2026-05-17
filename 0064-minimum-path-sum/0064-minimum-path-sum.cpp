class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Bottom UP Approach..
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,INT_MAX));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int minpath = min(dp[i+1][j],dp[i][j+1]);
                dp[i][j] = minpath+grid[i][j];
            }
        }
        return dp[0][0];
    }
};