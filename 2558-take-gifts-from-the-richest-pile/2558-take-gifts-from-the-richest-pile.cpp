class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>maxheap;
        for(int i=0;i<gifts.size();i++){
            maxheap.push(gifts[i]);
        }
        int data=0;
        while(k>0){
            data = sqrt(maxheap.top());
            maxheap.pop();
            maxheap.push(data);
            k--;
        }
        long long ans=0;
        while(!maxheap.empty()){
            ans+=maxheap.top();
            maxheap.pop();
        }
        return ans;
    }
};