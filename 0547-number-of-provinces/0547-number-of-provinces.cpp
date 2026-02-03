class Solution {
public:
    void DFS(int node,vector<bool>&visited,vector<vector<int>>&adj){
        if(visited[node]) return;
        visited[node] = 1;
        for(int i=0;i<visited.size();i++){
            if(adj[node][i]){
                DFS(i,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count_province =0;
        vector<bool>visited(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                count_province++;
                DFS(i,visited,isConnected);
            }
        }
        return count_province;
    }
};