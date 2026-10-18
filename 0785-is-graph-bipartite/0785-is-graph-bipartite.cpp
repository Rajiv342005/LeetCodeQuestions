class Solution {
public:
    bool check(vector<vector<int>>&graph,vector<char>&setChecker,int element){
        queue<int>q;
        q.push(element);
        while(!q.empty()){
            int node = q.front(); q.pop();
            char assign;
            if(setChecker[node]=='A'){
                assign = 'B';
            }
            else assign = 'A';
            for(int i=0;i<graph[node].size();i++){
                if(setChecker[graph[node][i]] == '*'){
                    setChecker[graph[node][i]] = assign;
                    q.push(graph[node][i]);
                }
                else if(setChecker[graph[node][i]] != assign) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<char>setChecker(n,'*');
        for(int i=0;i<n;i++){
            if(setChecker[i]=='*'){
                setChecker[i] = 'A';
                if(!check(graph,setChecker,i)) return false;
            }
        }
        return true;          
    }
};