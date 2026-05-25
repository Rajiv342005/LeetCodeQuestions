class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>incomingEdge(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int course = prerequisites[i][0];
            int prequisite = prerequisites[i][1];
            adj[prequisite].push_back(course);
            incomingEdge[course]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(incomingEdge[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            ans.push_back(course);
            for(int i=0;i<adj[course].size();i++){
                incomingEdge[adj[course][i]]--;
                if(incomingEdge[adj[course][i]]==0)
                q.push(adj[course][i]);
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};