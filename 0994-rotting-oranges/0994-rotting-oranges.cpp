class Solution {
public:
    bool Valid(int i,int j,int row,int col){
        return i>-1 && i<row&& j>-1 && j<col;
    }
    int orangesRotting(vector<vector<int>>& grid) {
       int row = grid.size();
       int col = grid[0].size();
       int freshOrange = 0;
       queue<pair<pair<int,int>,int>>q;
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1) freshOrange++;
            if(grid[i][j]==2) q.push({{i,j},0});
        }
       }
    // Yaha Hum up,down,left,right pe check karenge ki Rotten banega ki nahi given Orange.
       int i,j,timetaken = 0;
       while(!q.empty()){
        i = q.front().first.first;
        j = q.front().first.second;
        timetaken = q.front().second;
        q.pop();
        // Checking for Upward cell
        if(Valid(i-1,j,row,col) && grid[i-1][j]==1){
            freshOrange--;
            q.push({{i-1,j},timetaken+1});
            grid[i-1][j] =0;   // Assigning fresh oranges into rotten
        }
        // Checking for Downward cell
        if(Valid(i+1,j,row,col) && grid[i+1][j]==1){
            freshOrange--;
            q.push({{i+1,j},timetaken+1});
            grid[i+1][j] =0;   // Assigning fresh oranges into rotten
        }
        // Checking for leftward cell
        if(Valid(i,j-1,row,col) && grid[i][j-1]==1){
            freshOrange--;
            q.push({{i,j-1},timetaken+1});
            grid[i][j-1] =0;    // Assigning fresh oranges into rotten
        }
        // Checking for Downward cell
        if(Valid(i,j+1,row,col) && grid[i][j+1]==1){
            freshOrange--;
            q.push({{i,j+1},timetaken+1});
            grid[i][j+1] =0;   // Assigning fresh oranges into rotten
        }
       }
       if(freshOrange) return -1;
       return timetaken;
    }
};