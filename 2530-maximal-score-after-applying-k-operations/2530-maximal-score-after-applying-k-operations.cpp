class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score=0;
        priority_queue<int>maxheap(nums.begin(),nums.end());
        int data =0;
        while(k>0 && !maxheap.empty()){
            data = maxheap.top();
            maxheap.pop();
            score+=data;
            maxheap.push((data+2)/3);
            k--;
        }
        return score;
    }
};