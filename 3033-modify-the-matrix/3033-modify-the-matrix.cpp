class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<int>Maxcols(matrix[0].size());
        int Max=INT_MIN;
        for(int i=0;i<matrix[0].size();i++){
            Max = INT_MIN;
            for(int j=0;j<matrix.size();j++){
                if(matrix[j][i]>Max) Max=matrix[j][i];
            }
            Maxcols[i] = Max;
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==-1){
                    matrix[i][j] = Maxcols[j];
                }
            }
        }
        return matrix;
    }
};