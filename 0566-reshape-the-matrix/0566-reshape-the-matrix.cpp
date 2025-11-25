class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size()*mat[0].size()!=r*c) return mat;
        vector<int>nums(mat.size()*mat[0].size());
        int index=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                nums[index++] = mat[i][j];
            }
        }
        if(r==1) return {nums};
        vector<vector<int>>ans(r,vector<int>(c));
        index=0;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                ans[i][j] = nums[index++];
            }
        }
        return ans;
    }
};