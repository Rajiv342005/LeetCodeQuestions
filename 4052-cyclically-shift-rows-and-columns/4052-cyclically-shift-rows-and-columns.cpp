class Solution {
public:
    void rotateRow(vector<vector<int>>&grid,int k,int n,int idx){
        vector<int>nums = grid[idx];
        k = k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end()); 
        reverse(nums.begin(),nums.end());
        grid[idx] = nums;
        return;
    }
    void rotateCol(vector<vector<int>>&grid,int k,int col){
        int row = grid.size();
        vector<int>nums(row);
        k = k%row;
        for(int i=0;i<row;i++){
            nums[i] = grid[row-i-1][col];
        }
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        for(int i=0;i<row;i++){
            grid[i][col] = nums[row-i-1];
        }
        return;
    }
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0;i<n;i++){
            rotateRow(grid,rowShift[i],n,i);
        }
        for(int i=0;i<n;i++){
            rotateCol(grid,colShift[i],i);
        }
        return grid;
    }
};