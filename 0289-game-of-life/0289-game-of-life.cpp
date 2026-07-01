class Solution {
public:
    bool check(int m,int n,int row,int col){
        return m<row && n<col && m>=0 && n>=0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        // Making Eight Possibity to Move.
        vector<int>rows = {0,0,1,-1,1,-1,-1,1};
        vector<int>cols = {1,-1,0,0,1,-1,1,-1};
        vector<vector<int>>next = board;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int alive_neighbour = 0;
                for(int k=0;k<8;k++){
                    if(check(i+rows[k],j+cols[k],row,col)){
                        if(board[i+rows[k]][j+cols[k]]==1) alive_neighbour++;
                    }
                }
                // If Cell is Alive
                if(board[i][j]){
                    // if Less than 2 Neighbour is Alive
                    if(alive_neighbour<2 || alive_neighbour>3 ) next[i][j] = 0;
                } 
                // If Cell is Dead
                else{
                    // if Cell having Exactly 3 Alive Member.
                    if(alive_neighbour==3) next[i][j] = 1;
                }
            }
        }
        board = next;
        return;
    }
};