class Solution {
public:
    int MPS(int srow,int scol,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(srow>=grid.size() || scol>=grid[0].size()) return INT_MAX;
        if(srow==grid.size()-1 && scol==grid[0].size()-1) return grid[srow][scol];
        if(dp[srow][scol]!=-1) return dp[srow][scol];

        int rightmove = MPS(srow+1,scol,grid,dp);
        int downmove = MPS(srow,scol+1,grid,dp);

        int minpath = min(rightmove,downmove);
        return dp[srow][scol] =  minpath+grid[srow][scol];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return MPS(0,0,grid,dp);
    }
};