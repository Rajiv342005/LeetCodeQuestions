class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int Sum=0;
        for(int i=0;i<grid.size();i++){
            sort(grid[i].begin(),grid[i].end(),greater<int>());
        }
        int largest;
        for(int i=0;i<grid[0].size();i++){
            largest = INT_MIN;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]>largest) largest = grid[j][i];
                else continue;
            }
            Sum+=largest;
        }
        return Sum;
    }
};