class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int count=0;
        int Max1s=INT_MIN;
        int index=0;
        for(int i=0;i<mat.size();i++){
            count=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1) count++;
                else continue;
            }
            if(count>Max1s){
                Max1s = count;
                index = i;
            }
            else continue;
        }
        return {index,Max1s};
    }
};