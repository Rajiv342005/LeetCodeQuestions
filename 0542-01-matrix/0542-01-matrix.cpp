class Solution {
public:
    bool valid(int i,int j,int row,int col){
        return i>-1&&i<row&&j>-1&&j<col;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>>ans(row,vector<int>(col,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},1});
                }
            }
        } 
        int i,j,distance=0;
        while(!q.empty()){
            i = q.front().first.first;
            j = q.front().first.second;
            distance = q.front().second;
            q.pop();
            // Checking Upward
            if(valid(i-1,j,row,col) && mat[i-1][j]==1){
                ans[i-1][j] = distance;
                mat[i-1][j] = 0;
                q.push({{i-1,j},distance+1});
            }
            // Checking Downward
            if(valid(i+1,j,row,col) && mat[i+1][j]==1){
                ans[i+1][j] = distance;
                mat[i+1][j] = 0;
                q.push({{i+1,j},distance+1});
            }
            // Checking Leftward
            if(valid(i,j-1,row,col) && mat[i][j-1]==1){
                ans[i][j-1] = distance;
                mat[i][j-1] = 0;
                q.push({{i,j-1},distance+1});
            }
            // Checking Rightward
            if(valid(i,j+1,row,col) && mat[i][j+1]==1){
                ans[i][j+1] = distance;
                mat[i][j+1] = 0;
                q.push({{i,j+1},distance+1});
            }
        } 
        return ans;   
    }
};