class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
        if(visited[node]) return;
        visited[node] = true;
        for(int i=0;i<adj[node].size();i++){
            dfs(adj[node][i],adj,visited);
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int V = rooms.size();
        vector<vector<int>>adj(V);
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<rooms[i].size();j++){
                int des = rooms[i][j];
                adj[i].push_back(des); 
            }
        }
        dfs(0,adj,visited);
        for(int i=0;i<V;i++){
            if(visited[i]==0) return false;
        }
        return true;
    }
};