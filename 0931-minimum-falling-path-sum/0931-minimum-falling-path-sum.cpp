class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int minpathsum = INT_MAX;
        int m  = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n+2,INT_MAX));
        for(int i=1;i<=n;i++){
            dp[m-1][i] = grid[m-1][i-1];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=1;j<=n;j++){
                int b1 = dp[i+1][j];
                int b2 = dp[i+1][j-1];
                int b3 = dp[i+1][j+1];
                dp[i][j] = min({b1,b2,b3})+grid[i][j-1];
            }
        }
        for(int i=0;i<=n;i++){
            minpathsum = min(minpathsum,dp[0][i+1]);
        }
        return minpathsum;
    }
};