class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>p;
        for(int i=0;i<stones.size();i++){
            p.push(stones[i]);
        }
        while(p.size()>1){
            int w1 = p.top(); p.pop();
            int w2 = p.top(); p.pop();
            if((w1-w2)>0){
                p.push(w1-w2);
            }
            else continue;
        }
        if(p.empty()) return 0;
        else return p.top();
    }
};