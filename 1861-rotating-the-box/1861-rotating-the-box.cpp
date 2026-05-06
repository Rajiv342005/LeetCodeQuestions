class Solution {
public:
    void dropstone(int row,int col,vector<vector<char>>&temp){
        int r = temp.size();
        int idx = row+1;
        int currrow = row;
        while(idx<r){
            if(temp[idx][col]=='*' || temp[idx][col]=='#') return;
            else if(temp[idx][col]=='.'){
                swap(temp[idx][col],temp[currrow][col]);
                currrow = idx;
            }
            idx++;
        }
        return;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int row = boxGrid.size();
        int col = boxGrid[0].size();
        vector<vector<char>>temp(col,vector<char>(row));
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                temp[i][j] = boxGrid[row-j-1][i];    
            }
        }
        for(int i=temp.size()-1;i>=0;i--){
            for(int j=temp[0].size()-1;j>=0;j--){
                if(temp[i][j]=='#'){
                    dropstone(i,j,temp);
                }
                else continue;
            }
        }
        return temp;
    }
};