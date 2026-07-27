class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int val: nums){
            if(pq.size()==2){
                if(pq.top()<val){
                    pq.pop();
                }
                else continue;
            }
            pq.push(val);
        }
        int firstmax = pq.top()-1;
        pq.pop();
        int secondmax = pq.top()-1;
        return firstmax*secondmax;
    }
};