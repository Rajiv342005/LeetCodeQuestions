class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            vector<int>Rows(matrix.size(),1);
            vector<int>Cols(matrix.size(),1);
            for(int j=0;j<matrix[i].size();j++){
                Rows[matrix[i][j]-1]--;
            }
            for(int j=0;j<matrix.size();j++){
                Cols[matrix[j][i]-1]--;
            }
            for(int k=0;k<Rows.size();k++){
                if(Rows[k]!=0) return false;
            }
            for(int k=0;k<Cols.size();k++){
                if(Cols[k]!=0) return false;
            }
        }
        return true;
    }
};