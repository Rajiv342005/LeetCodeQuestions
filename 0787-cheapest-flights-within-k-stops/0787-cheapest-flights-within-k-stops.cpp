class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto flight:flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adj[from].push_back({to,price});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minheap;
        vector<int> stopsArr(n,INT_MAX);
        minheap.push({0,{src,0}}); // {Price,{Node,stops}};
        while(!minheap.empty()){
            auto pair = minheap.top();
            minheap.pop();
            int price = pair.first;
            int node = pair.second.first;
            int stops = pair.second.second;

            if(node==dst) return price;
            if(stops>k || stopsArr[node]<stops) continue;
            stopsArr[node] = stops;
            for(int i=0;i<adj[node].size();i++){
                minheap.push({adj[node][i].second+price,{adj[node][i].first,stops+1}});
            }
        }
        return -1;

    }
};