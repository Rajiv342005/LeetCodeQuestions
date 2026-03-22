class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(obstacleGrid[row-1][col-1]) return 0;
        vector<vector<unsigned int>>dp(row,vector<unsigned int>(col,0));
        // Forming the Base Case of Bottom up Approach.
        for(int i=row-1;i>=0;i--){
            if(obstacleGrid[i][col-1]){
                break;
            }
            else dp[i][col-1] =1;
        }
        for(int j=col-1;j>=0;j--){
            if(obstacleGrid[row-1][j]){
                break;
            }
            else dp[row-1][j] = 1;
        }
        for(int i=row-2;i>=0;i--){
            for(int j=col-2;j>=0;j--){
                if(obstacleGrid[i][j]){
                    dp[i][j] =0;
                }
                else dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};