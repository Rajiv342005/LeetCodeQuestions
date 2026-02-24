class Solution {
public:
    int DFS(int node,vector<vector<int>>&adj,vector<int>&low,vector<int>&disc,int &timer,int parent,vector<vector<int>>&bridge){
        if(disc[node]!=-1){
            return disc[node];
        }
        timer++;
        disc[node]=low[node]=timer;
        for(int i=0;i<adj[node].size();i++){
            int neighbour = adj[node][i];
            if(neighbour==parent) continue;
            low[node] = min(low[node],DFS(neighbour,adj,low,disc,timer,node,bridge));
            if(disc[node]<low[neighbour]) bridge.push_back({node,neighbour});
        }
        return low[node];
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            int first = connections[i][0];
            int second = connections[i][1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        vector<vector<int>>bridge;
        vector<int>low(n,-1);
        vector<int>disc(n,-1);
        int timer = -1;
        int parent =-1;
        DFS(0,adj,low,disc,timer,parent,bridge);
        return bridge;
    }
};