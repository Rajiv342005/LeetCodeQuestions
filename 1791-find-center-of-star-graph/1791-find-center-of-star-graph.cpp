class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int>used;
        used.insert(edges[0][0]);
        used.insert(edges[0][1]);
        if(used.count(edges[1][0])) return edges[1][0];
        return edges[1][1];
    }
};