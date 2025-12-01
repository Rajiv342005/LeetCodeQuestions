class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_set<int>used;
        for(int i=0;i<nums.size();i++){
            if(used.find(nums[i])!=used.end()){
                ans.push_back(nums[i]);
            }
            else{
                used.insert(nums[i]);
            }
        }
        return ans;
    }
};