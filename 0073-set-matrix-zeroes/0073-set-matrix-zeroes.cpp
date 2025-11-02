class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set <int> rows;
        unordered_set <int> col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(rows.find(i)!=rows.end() || col.find(j)!=col.end()){
                    matrix[i][j]=0;
                }
            }
        }
        return ;
    }
};