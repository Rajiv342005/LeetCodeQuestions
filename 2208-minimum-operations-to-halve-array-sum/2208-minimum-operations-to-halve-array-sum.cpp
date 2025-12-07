class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>maxheap(nums.begin(),nums.end());
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        double half = sum/2.0;
        double sum2=sum;
        int ops =0;
        double data = 0;
        while(sum2>half){
            data = maxheap.top()/2;
            sum2-=data;
            ops++;
            maxheap.pop();
            maxheap.push(data);
        }
        return ops;
    }
};