class Solution {
public:
    bool CheckGrid(vector<vector<int>>&grid,vector<vector<bool>>&visited){
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0){
                    if(grid[i][j]==1 || grid[i][j]==2 || grid[i][j]==-1) continue;
                    else return false;
                }
            }
        }
        return true;
    }
    bool check(int row,int col,vector<vector<int>>&grid){
        return row>=0 && row<grid.size() && col>=0 && col<grid[0].size();
    }
    vector<int>row = {1,-1,0,0};
    vector<int>col = {0,0,1,-1};
    int UniquePath3(vector<vector<int>>&grid,vector<vector<bool>>&visited,int str,int stc){
        if(str>=grid.size() || str<0 ) return 0;
        if(stc>=grid[0].size() || stc<0 ) return 0;
        if(grid[str][stc]==2){
            if(CheckGrid(grid,visited)) return 1;
            return 0;
        }
        int ways = 0;
        // Now Walk to all Four Directions.
        for(int i=0;i<4;i++){
            int Row = str+row[i];
            int Col = stc+col[i];
            if(check(Row,Col,grid) && !visited[Row][Col] && grid[Row][Col]!=-1){
                visited[Row][Col] = 1;
                ways+=UniquePath3(grid,visited,Row,Col);
                visited[Row][Col] = 0;
            }
        } 
        return ways;  
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int str,stc;
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    str = i;
                    stc =j;
                    break;
                }
            }
        }
        visited[str][stc] =1;
        return UniquePath3(grid,visited,str,stc); 
    }
};