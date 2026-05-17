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
                int minnode = INT_MAX;
                for(int k=1;k<=n;k++){
                    if(j==k) continue;
                    minnode = min(minnode,dp[i+1][k]);

                }
                dp[i][j] = minnode+grid[i][j-1];
            }
        }
        for(int i=0;i<=n;i++){
            minpathsum = min(minpathsum,dp[0][i+1]);
        }
        return minpathsum;
    }
};