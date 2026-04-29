class Solution {
public:
    bool check(int row,int col,vector<vector<char>>&grid){
        return row>=0 && row<grid.size() && col>=0 &&col<grid[0].size();
    }
    bool DetectCycle(pair<int,int>parent,pair<int,int>node,char value,vector<vector<char>>&grid,vector<vector<bool>>&visited){
        visited[node.first][node.second] = 1;
        vector<int>rows = {1,-1,0,0};
        vector<int>cols = {0,0,-1,1};
        for(int i=0;i<4;i++){
            int r = node.first+rows[i];
            int c = node.second+cols[i];
            if(check(r,c,grid) && grid[r][c]==value){
                if(visited[r][c]){
                    if(!(r==parent.first&&c==parent.second)) return true;
                }
                else{
                    if(DetectCycle(node,{r,c},grid[node.first][node.second],grid,visited)) return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j]){
                    if(DetectCycle({-1,-1},{i,j},grid[i][j],grid,visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};