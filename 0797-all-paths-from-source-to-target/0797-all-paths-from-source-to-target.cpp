class Solution {
public:

    void DFS(int node,vector<vector<int>>&adj,vector<vector<int>>&ans,vector<int>path){
        if(node==adj.size()-1){
            path.push_back(node);
            ans.push_back(path);
            return;
        }
        path.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            DFS(adj[node][i],adj,ans,path);
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>>adj(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<vector<int>>ans;
        vector<int>path;
        DFS(0,adj,ans,path);
        return ans;
    }
};