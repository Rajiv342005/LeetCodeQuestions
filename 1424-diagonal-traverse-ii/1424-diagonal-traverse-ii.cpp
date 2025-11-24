class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxCol=0;
        for(int i=0;i<nums.size();i++){
            if(maxCol<nums[i].size()){
                maxCol = nums[i].size();
            }
            else continue;
        }
        vector<vector<int>>mat(nums.size()+maxCol-1);
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                mat[i+j].push_back(nums[i][j]);
            }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=mat[i].size()-1;j>=0;j--){
                ans.push_back(mat[i][j]);
            }
        }
        return ans;
    }
};