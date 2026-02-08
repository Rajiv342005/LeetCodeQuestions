class Solution {
public:
    bool check(int i,int j,int row,int col){
        return i>-1&&i<row&&j>-1&&j<col;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];
        if(oldcolor==color) return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = color;
        vector<int>rows = {1,-1,0,0};
        vector<int>cols = {0,0,1,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                if(check(row+rows[i],col+cols[i],image.size(),image[0].size())&& image[row+rows[i]][col+cols[i]]==oldcolor){
                    q.push({row+rows[i],col+cols[i]});
                    image[row+rows[i]][col+cols[i]] = color;
                }
            }
        }
        return image;    
    }
};