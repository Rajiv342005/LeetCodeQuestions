class Solution {
public:
    bool GridFormation(int row,int col,int m,int n,vector<string>&grid){
        if(row>=m || col>=n) return false;
        if(row==m-1 && col==n-1) return true;

        // Case1: Blocking the DownSide and Moving onto the RigftSide.
        if(row<m-1){
            grid[row+1][col] = '#';
            if(GridFormation(row,col+1,m,n,grid)) return true;
            grid[row+1][col] = '.';    
        }
        else 
        if(GridFormation(row,col+1,m,n,grid)) return true;
        // Case2: Blocking the RightSide and Moving onto the RightSide.
        if(col<n-1){
            grid[row][col+1] = '#';
            if(GridFormation(row+1,col,m,n,grid)) return true;
            grid[row][col+1] = '.';    
        }
        else 
        if(GridFormation(row+1,col,m,n,grid)) return true;

        return false;
    }
    vector<string> createGrid(int m, int n) {
       vector<string>grid(m,string(n,'.'));
       GridFormation(0,0,m,n,grid);
       return grid;
    }
};