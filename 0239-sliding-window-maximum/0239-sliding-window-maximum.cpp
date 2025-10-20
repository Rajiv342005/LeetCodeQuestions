class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> d;
        for(int i=0;i<k;i++){
            while(d.size() && nums[d.back()]<nums[i]){
                d.pop_back();
            }
            d.push_back(i);
        }
        ans.push_back(nums[d.front()]);
        for(int i=k;i<nums.size();i++){
            if((i-k)==d.front()){
                d.pop_front();
            }
            while(d.size()&&nums[d.back()]<nums[i]){
                d.pop_back();
            }
            d.push_back(i);
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};