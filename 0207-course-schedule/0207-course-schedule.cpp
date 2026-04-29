class Solution {
public:
    bool DetectCycle(int node,vector<bool>&visited,vector<bool>&pathvisited,vector<vector<int>>&adj){
        visited[node] = 1;
        pathvisited[node] = 1;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                if(DetectCycle(adj[node][i],visited,pathvisited,adj)) return true;
            }
            else if(pathvisited[adj[node][i]]) return true;
        }
        pathvisited[node] =0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<bool>visited(numCourses,0);
        vector<bool>pathvisited(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            int course = prerequisites[i][0];
            int preq = prerequisites[i][1];
            adj[course].push_back(preq);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(DetectCycle(i,visited,pathvisited,adj)) return false;
            }
        }
        return true;
    }
};