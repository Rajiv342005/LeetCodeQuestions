class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        for(int i=0;i<nums.size();i++){
            minheap.push(make_pair(nums[i],i));
        }
        while(k--){
            int index = minheap.top().second;
            minheap.pop();
            nums[index]*=multiplier;
            minheap.push(make_pair(nums[index],index));
        }
        return nums;
    }
};