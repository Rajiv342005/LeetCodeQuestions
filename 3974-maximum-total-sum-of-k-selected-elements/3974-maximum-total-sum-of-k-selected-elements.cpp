class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        long long totalSum = 0;
        while(k>0){
            if(mul>=1){
                totalSum += (long long)mul*pq.top();
                mul--;
            }
            else totalSum += pq.top();
            k--;
            pq.pop();
        }
        return totalSum;
    }
};