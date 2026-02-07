class Solution {
public:
    bool check(int i,int j,int row,int col){
        return i>-1&&i<row&&j>-1&&j<col;
    }
    void BFS(int i, int j,vector<vector<char>>&grid){
        vector<int>rows = {-1,1,0,0};
        vector<int>cols = {0,0,-1,1};
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                if(check(row+rows[i],col+cols[i],grid.size(),grid[0].size()) && grid[row+rows[i]][col+cols[i]]=='1'){
                    q.push({row+rows[i],col+cols[i]});
                    grid[row+rows[i]][col+cols[i]]='0';
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int Island = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    Island++;
                    BFS(i,j,grid);
                }
            }
        }
        return Island;
    }
};