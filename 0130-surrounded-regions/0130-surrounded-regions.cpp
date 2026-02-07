class Solution {
public:
    bool check(int i,int j,int row,int col){
        return i>-1&&i<row&&j>-1&&j<col;
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<char>>ans(row,vector<char>(col,'X'));
        queue<pair<int,int>>q;
        // Inserting Element that are at boundary of board Matrix..
        for(int i=0;i<col;i++){
            // Upper Boundary
            if(board[0][i]=='O') q.push({0,i});
            // Lower Boundary
            if(board[row-1][i]=='O') q.push({row-1,i});
        }
        for(int i=0;i<row;i++){
            // Leftmost Boundary
            if(board[i][0]=='O') q.push({i,0});
            // Rightmost Boundary
            if(board[i][col-1]=='O') q.push({i,col-1});
        }
        vector<int> rows = {-1,1,0,0};
        vector<int> cols = {0,0,-1,1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            ans[r][c] = 'O';
            for(int i=0;i<4;i++){
                if(check(r+rows[i],c+cols[i],row,col) && board[r+rows[i]][c+cols[i]] == 'O'){
                    board[r+rows[i]][c+cols[i]] = 'X'; // For Marking purpose such that this node is already visited.
                    q.push({r+rows[i],c+cols[i]});
                }
            }
        }
        board = ans;
        return ;
    }
};