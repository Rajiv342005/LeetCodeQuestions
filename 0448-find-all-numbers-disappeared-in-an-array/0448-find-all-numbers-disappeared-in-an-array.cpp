class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_set<int>used;
        for(int i=0;i<nums.size();i++){
            used.insert(nums[i]);
        }
        for(int i=1;i<=nums.size();i++){
            if(used.find(i)!=used.end()){
                continue;
            }
            else ans.push_back(i);
        }
        return ans;
    }
};