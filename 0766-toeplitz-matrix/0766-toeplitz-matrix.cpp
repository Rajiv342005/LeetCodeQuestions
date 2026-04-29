class Solution {
public:
    bool DiagonalTraversal(int row,int col,vector<vector<int>>&matrix,int value){
        if(!(row>=0 && row<matrix.size()&& col>=0 && col<matrix[0].size())) return true;
        if(matrix[row][col]!=value) return false;
        return DiagonalTraversal(row+1,col+1,matrix,matrix[row][col]);
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            if(!DiagonalTraversal(i+1,1,matrix,matrix[i][0])) return false;
        }
        for(int j=0;j<n;j++){
            if(!DiagonalTraversal(1,j+1,matrix,matrix[0][j])) return false;
        }
        return true;
    }

};