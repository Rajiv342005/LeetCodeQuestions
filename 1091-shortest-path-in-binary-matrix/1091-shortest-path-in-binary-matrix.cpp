class Solution {
public:
    bool check(int row,int col,int Row,int Col){
        return row>=0 && row<Row && col>=0 && col<Col;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Handling the Edge Cases..
        int rs = grid.size();
        int cs = grid[0].size();
        if(grid[0][0]==1 || grid[rs-1][cs-1]==1) return -1;

        // Vector for travelling in 8 directions.
        vector<int>row = {-1,0,1,1,-1,-1,0,1};
        vector<int>col = {-1,-1,-1,0,0,1,1,1};

        // Creating a queue which store the row,col and distance from source.
        queue<pair<pair<int,int>,int>>q;

        // Insert the source Node into the queue.
        q.push({{0,0},1});
        grid[0][0] = 1;

        // Now Travelling the Node Using BFS Search.
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int row_no = node.first.first;
            int col_no = node.first.second;
            int distance = node.second;

            // Edge Case Handling where grid Contain Only one element [[0]].
            if(row_no==rs-1 && col_no==cs-1) return distance;

            for(int i=0;i<8;i++){
                int Row = row_no + row[i];
                int Col = col_no + col[i];

                // Here I am checking whether the Row and Col is inside grid or not.
                if(check(Row,Col,rs,cs) && grid[Row][Col]==0){
                    if(Row==rs-1 && Col==cs-1) return distance+1;
                    q.push({{Row,Col},distance+1});
                    grid[Row][Col] = 1;
                }
            }
        }
        return -1;    
    }
};