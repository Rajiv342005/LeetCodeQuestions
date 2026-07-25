class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int,vector<int>,greater<int>>minheap;
        while(n>0){
            int digit = n%10;
            if(minheap.size()==2){
                if(minheap.top() < digit){
                    minheap.pop();
                    minheap.push(digit);
                }     
            }
            else minheap.push(digit);
            n = n/10;
        }
        int secondmax = minheap.top();
        minheap.pop();
        int firstmax = minheap.top();
        return firstmax*secondmax;
    }
};