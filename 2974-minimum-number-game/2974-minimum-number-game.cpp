class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>p;
        for(int i=0;i<nums.size();i++){
            p.push(nums[i]);
        }
        vector<int>ans;
        while(p.size()>1){
            int Alice = p.top();p.pop();
            int Bob = p.top();p.pop();
            ans.push_back(Bob);
            ans.push_back(Alice);
        }
        while(!p.empty()){
            ans.push_back(p.top());
            p.pop();
        }
        return ans;
    }
};