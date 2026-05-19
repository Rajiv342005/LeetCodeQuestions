class Solution {
public:
    int MOD = 1e9+7;
    int CountPath(int row,int col,vector<vector<int>>&grid,int k,int rem,vector<vector<vector<int>>>&dp){
        if(row>=grid.size() || col>=grid[0].size()) return 0;
        rem=(rem+grid[row][col])%k;
        if(row==grid.size()-1 && col==grid[0].size()-1){
            if(rem==0) return 1;
            return 0;
        };
        if(dp[row][col][rem]!=-1) return dp[row][col][rem];
        int rightmove = CountPath(row+1,col,grid,k,rem,dp);
        int downmove = CountPath(row,col+1,grid,k,rem,dp);
        return dp[row][col][rem] = (rightmove+downmove)%MOD;    
    };
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k,-1)));
        return CountPath(0,0,grid,k,0,dp);
    }
};