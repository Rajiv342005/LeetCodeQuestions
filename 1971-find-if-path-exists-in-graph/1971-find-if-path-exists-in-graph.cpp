class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size()==0) return 1;
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int src = edges[i][0];
            int des = edges[i][1];
            adj[src].push_back(des);
            adj[des].push_back(src);
        }
        queue<int>q;
        vector<bool>visited(n,0);
        q.push(source);
        visited[source] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                if(adj[node][i]==destination) return true;
                if(!visited[adj[node][i]]){
                    q.push(adj[node][i]);
                    visited[adj[node][i]] = 1;
                }
            }
        }
        return false;    
    }
};