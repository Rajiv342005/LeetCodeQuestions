class Solution {
public:
    bool check(int r,int c,int row,int col){
        return r<row && r>=0 && c<col && c>=0;
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        vector<int> rmove = {1,-1,0,0};
        vector<int> cmove = {0,0,1,-1};
        queue<vector<int>> q;
        for(auto& it : sources){
            int r = it[0], c = it[1], color = it[2];
            ans[r][c] = color;
            time[r][c] = 0;
            q.push({r, c, color, 0});
        }
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int r = temp[0];
            int c = temp[1];
            int color = temp[2];
            int currtime = temp[3];
            for(int i=0;i<4;i++){
                int nr = r + rmove[i];
                int nc = c + cmove[i];
                if(check(nr,nc,n,m)){
                    if(time[nr][nc] > currtime + 1){
                        time[nr][nc] = currtime + 1;
                        ans[nr][nc] = color;
                        q.push({nr, nc, color, currtime + 1});
                    }
                    else if(time[nr][nc] == currtime + 1 && ans[nr][nc] < color){
                        ans[nr][nc] = color;
                        q.push({nr, nc, color, currtime + 1});
                    }
                }
            }
        }
        return ans;
    }
};