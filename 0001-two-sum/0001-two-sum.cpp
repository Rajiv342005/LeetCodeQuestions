class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        int found;
        for(int i=0;i<nums.size();i++){
            found = target-nums[i];
            if(m.count(found)){
                return {m[found],i};
            }
            else{
                m[nums[i]] = i;
            }
        }
        return {};
    }
};