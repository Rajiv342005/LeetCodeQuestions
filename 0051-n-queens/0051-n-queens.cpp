class Solution {
public:
    bool isSafe(vector<string>&board,int row,int col,int n){
        // Check Vertically Up
        for(int j=0;j<row;j++){
            if(board[j][col]=='Q') return false;
        }
        // Check Diagonal Left
        int r = row;
        int c = col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        // Check Diagonal Right
        int r1 = row;
        int c1 = col;
        while(r1>=0 && c1<n){
            if(board[r1][c1]=='Q') return false;
            r1--;
            c1++;
        }
        return true;
    }
    void NQueen(vector<string>&board,int row,int n,vector<vector<string>>&ans){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j,n)){
                board[row][j] = 'Q';
                NQueen(board,row+1,n,ans);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        NQueen(board,0,n,ans);
        return ans;
    }
};