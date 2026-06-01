class Solution {
public:
    int minimumCost(vector<int>& cost) {
        priority_queue<int,vector<int>>pq;
        for(auto val:cost){
            pq.push(val);
        }
        int mincost = 0;
        int turn =0;
        while(!pq.empty()){
            if(turn<2){
                turn++;
                int price = pq.top();
                pq.pop();
                mincost+=price;
            }
            else{
                turn =0;
                pq.pop();
            }
        }
        return mincost;
    }
};