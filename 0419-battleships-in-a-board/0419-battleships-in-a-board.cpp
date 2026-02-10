class Solution {
public:
    bool check(int i,int j,int row,int col){
        return i>-1&&i<row&&j>-1&&j<col;
    }
    void BFS(int r,int c,vector<vector<char>>& board){
        vector<int> rows = {1,-1,0,0};
        vector<int> cols = {0,0,-1,1};
        queue<pair<int,int>>q;
        q.push({r,c});
        board[r][c] = '.';
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                if(check(row+rows[i],col+cols[i],board.size(),board[0].size())&& board[row+rows[i]][col+cols[i]]=='X'){
                    board[row+rows[i]][col+cols[i]]='.';
                    q.push({row+rows[i],col+cols[i]});
                }
            }
        }
        return;
    }
    int countBattleships(vector<vector<char>>& board) {
      int Battleship = 0;
      for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='X'){
                Battleship++;
                BFS(i,j,board);
            }
        }
      }
      return Battleship;  
    }
};