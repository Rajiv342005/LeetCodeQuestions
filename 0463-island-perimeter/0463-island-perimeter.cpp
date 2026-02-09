class Solution {
public:
    bool check(int i,int j,int row,int col){
        return i>-1&&i<row&&j>-1&&j<col;
    }
    int peri(int row,int col,vector<vector<int>>&grid){
        int count=0;
        vector<int> rows = {0,0,-1,1};
        vector<int> cols = {1,-1,0,0};
        for(int i=0;i<4;i++){
            if(check(row+rows[i],col+cols[i],grid.size(),grid[0].size())&& !grid[row+rows[i]][col+cols[i]]){
                count++;
            }
            else if(!check(row+rows[i],col+cols[i],grid.size(),grid[0].size())) count++;
        }
        return count;
    }
    void BFS(int r,int c,vector<vector<int>>&grid,int &perimeter,vector<vector<int>>&gridy){
        vector<int> rows = {0,0,-1,1};
        vector<int> cols = {1,-1,0,0};
        queue<pair<int,int>>q;
        int row,col;
        q.push({r,c});
        perimeter+=peri(r,c,gridy);
        grid[r][c] = 0;
        while(!q.empty()){
            row = q.front().first;
            col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                if(check(row+rows[i],col+cols[i],grid.size(),grid[0].size())&&grid[row+rows[i]][col+cols[i]]){
                    q.push({row+rows[i],col+cols[i]});
                    perimeter+=peri(row+rows[i],col+cols[i],gridy);
                    grid[row+rows[i]][col+cols[i]] = 0;
                }
            }
        }
        return;
    }
    int islandPerimeter(vector<vector<int>>& gridy) {
       vector<vector<int>>grid = gridy;
       int perimeter =0;
       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]){
                BFS(i,j,grid,perimeter,gridy);
            }
        }
       }
       return perimeter; 
    }
};