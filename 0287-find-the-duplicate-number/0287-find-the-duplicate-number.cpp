class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>used;
        for(int i=0;i<nums.size();i++){
            if(used.find(nums[i]) != used.end()){
                return nums[i];
            }
            else{
                used.insert(nums[i]);
            }
        }
        return -1;
    }
};