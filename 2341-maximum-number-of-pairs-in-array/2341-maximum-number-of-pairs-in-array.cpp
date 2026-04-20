class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int countpair = 0;
        unordered_set<int>used;
        for(int i=0;i<nums.size();i++){
            if(used.count(nums[i])){
                countpair++;
                used.erase(nums[i]);
            }
            else used.insert(nums[i]);
        }
        return {countpair,(int)nums.size()-2*countpair};
    }
};