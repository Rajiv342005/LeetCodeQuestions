class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<points.size();i++){
            int first = abs(points[i][0]);
            int second = abs(points[i][1]);
            int dist = first*first+second*second;
            pq.push({dist,i});
        }
        vector<vector<int>>ans(k);
        for(int i=0;i<k;i++){
            int p1 = points[pq.top().second][0];
            int p2 = points[pq.top().second][1];
            ans[i] = {p1,p2};
            pq.pop();
        }
        return ans;
    }
};