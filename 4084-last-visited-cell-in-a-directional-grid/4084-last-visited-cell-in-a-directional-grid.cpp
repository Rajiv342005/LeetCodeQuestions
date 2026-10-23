class Solution {
public:
    bool check(int row,int col,vector<vector<char>>&grid){
        return (row>=0 && row<grid.size() && col>=0 && col<grid[0].size());
    }
    vector<int> LVC(vector<vector<char>>&grid,int rowN,int colN,vector<vector<bool>>&visited){
        visited[rowN][colN] = true;
        if(grid[rowN][colN] == 'L'){
            if(check(rowN,colN-1,grid)){
                if(visited[rowN][colN-1]) return {rowN,colN};
                else return LVC(grid,rowN,colN-1,visited);
            }
        }
        else if(grid[rowN][colN] == 'R'){
            if(check(rowN,colN+1,grid)){
                if(visited[rowN][colN+1]) return {rowN,colN};
                else return LVC(grid,rowN,colN+1,visited);
            }
        }
        else if (grid[rowN][colN] == 'U'){
            if(check(rowN-1,colN,grid)){
                if(visited[rowN-1][colN]) return {rowN,colN};
                else return LVC(grid,rowN-1,colN,visited);
            }
        }
        else {
            if(check(rowN+1,colN,grid)){
                if(visited[rowN+1][colN]) return {rowN,colN};
                else return LVC(grid,rowN+1,colN,visited);
            }
        }
        return {rowN,colN};
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        return LVC(grid,0,0,visited);
    }
};