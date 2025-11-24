class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<vector<int>>ans(mat.size()+mat[0].size()-1);
        vector<int>nums;
        bool flag = true;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                ans[i+j].push_back(mat[i][j]);
            }
        }
        for(int i=0;i<ans.size();i++){
            if(flag){
                for(int j=ans[i].size()-1;j>=0;j--){
                    nums.push_back(ans[i][j]);
                }
            }
            else{
                for(int j=0;j<ans[i].size();j++){
                    nums.push_back(ans[i][j]);
                }
            }
            flag = !flag;
        }
        return nums;
    }
};