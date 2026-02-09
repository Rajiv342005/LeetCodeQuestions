class Solution {
public:
    bool check(int i,int j,int row,int col){
        return i>-1&&i<row&&j>-1&&j<col;
    }
    void BFS(int r,int c,vector<vector<int>>&grid,int &MaxArea){
        vector<int> rows = {-1,1,0,0};
        vector<int> cols = {0,0,1,-1};
        queue<pair<int,int>>q;
        q.push({r,c});
        grid[r][c] = 0;
        int row,col;
        int CurrArea = 1;
        while(!q.empty()){
            row = q.front().first;
            col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                if(check(row+rows[i],col+cols[i],grid.size(),grid[0].size())&&grid[row+rows[i]][col+cols[i]]){
                    CurrArea++;
                    q.push({row+rows[i],col+cols[i]});
                    grid[row+rows[i]][col+cols[i]] = 0;
                }
            }
        }
        MaxArea = max(MaxArea,CurrArea);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int MaxArea = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]) BFS(i,j,grid,MaxArea);
            }
        }
        return MaxArea;
    }
};