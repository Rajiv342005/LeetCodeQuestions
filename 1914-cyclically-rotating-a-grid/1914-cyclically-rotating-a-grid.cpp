class Solution {
public:
    // sr-->Starting Row
    // sc-->Starting Col
    // er-->Ending Row
    // ec-->Ending Col
    void layerwiseRotation(vector<vector<int>>&grid,vector<vector<int>>&mat,int sr,int sc,int er,int ec,int k){
        int perimeter = 2*((er-sr+1)+(ec-sc+1))-4;
        k %= perimeter;
        while(k--){
            // Rotating Starting Row.
            for(int i=sc+1;i<=ec;i++){
                mat[sr][i-1] = grid[sr][i];
            }
            // Rotating Ending Column.
            for(int j=sr+1;j<=er;j++){
                mat[j-1][ec] = grid[j][ec];
            }
            // Rotating Ending Row.
            for(int k=ec-1;k>=sc;k--){
                mat[er][k+1] = grid[er][k];
            }
            // Rotating Starting Column.
            for(int l=er-1;l>=sr;l--){
                mat[l+1][sc] = grid[l][sc];
            }
            grid = mat;
        }
        return;
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int endrow = grid.size();
        int endcol = grid[0].size();
        int startrow=0;
        int startcol=0;
        vector<vector<int>>mat=grid;
        while(startrow<endrow && startcol<endcol){
            layerwiseRotation(grid,mat,startrow,startcol,endrow-1,endcol-1,k);
            startrow++;
            startcol++;
            endrow--;
            endcol--;
        }
        return mat;
    }
};