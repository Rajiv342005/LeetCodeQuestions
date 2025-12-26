class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        priority_queue<int>p;
        for(int i=0;i<capacity.size();i++){
            p.push(capacity[i]);
        }
        int sum=0;
        for(int i=0;i<apple.size();i++){
            sum+=apple[i];
        }
        int count=0;
        while(!p.empty() && sum>0){
            count++;
            sum-=p.top();p.pop();
        }
        return count;
    }
};