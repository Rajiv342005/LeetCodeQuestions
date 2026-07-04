class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto road:roads){
            int ai = road[0];
            int bi = road[1];
            int distance = road[2];
            adj[ai].push_back({bi,distance});
            adj[bi].push_back({ai,distance});
        }
        vector<bool>visited(n+1,0);
        queue<int>q;
        q.push(1);
        visited[1] = 1;
        int mincost = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                int city = adj[node][i].first;
                int dist = adj[node][i].second;
                mincost = min(mincost,dist);
                if(!visited[adj[node][i].first]){
                    q.push(city);
                    visited[adj[node][i].first] = 1;
                }
            }
        }
        return mincost;
    }
};