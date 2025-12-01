class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int>used;
        vector<int>ans;
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