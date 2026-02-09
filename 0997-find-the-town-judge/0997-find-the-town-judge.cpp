class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>Indegree(n,0);
        vector<int>Outdegree(n,0);
        for(int i=0;i<trust.size();i++){
            int firstperson = trust[i][1];
            int secondperson = trust[i][0];
            Indegree[firstperson-1]++;
            Outdegree[secondperson-1]++;
        }
        for(int i=0;i<n;i++){
            if(Indegree[i]==n-1 && Outdegree[i]==0) return i+1;
        }
        return -1;
    }
};