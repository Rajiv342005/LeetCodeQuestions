class Solution {
public:
    bool check(int r,int c,int row,int col){
        return r>=0 && r<row && c>=0 && c<col;
    }
    bool DFS(int i,int j,int pointer,string&word,vector<vector<char>>&board){
        if(pointer==word.size()) return true;
        vector<int>rows = {1,-1,0,0};
        vector<int>cols = {0,0,-1,1};
        for(int k=0;k<4;k++){
            int row = i+rows[k];
            int col = j+cols[k];
            if(check(row,col,board.size(),board[0].size()) && board[row][col]==word[pointer]){
                char temp = board[row][col];
                board[row][col] = '#';
                if(DFS(row,col,pointer+1,word,board)) return true;
                board[row][col]= temp;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if((board.size()*board[0].size())<word.size()) return false;
      int pointer=0;
      for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]==word[pointer]){
                board[i][j] = '#';
                if(DFS(i,j,pointer+1,word,board)) return true;
                board[i][j] = word[pointer];
            }
        }
      }
      return false;  
    }
};