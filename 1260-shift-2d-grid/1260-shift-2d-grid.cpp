class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans = grid;
        while(k--){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    ans[i][j] = grid[i][(n-1+j)%n];
                }
            }
            grid = ans;
            for(int i=0;i<m;i++){
                ans[i][0] = grid[(m-1+i)%m][0];
            }
            grid = ans;
        }
        return ans;  
    }
};