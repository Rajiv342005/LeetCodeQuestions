class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>maxheap(piles.begin(),piles.end());
        int data =0;
        while(k>0){
            data = maxheap.top();
            maxheap.pop();
            maxheap.push((data+1)/2);
            k--;
        }
        int sum=0;
        while(!maxheap.empty()){
            sum+=maxheap.top();
            maxheap.pop();
        }
        return sum;
    }
};