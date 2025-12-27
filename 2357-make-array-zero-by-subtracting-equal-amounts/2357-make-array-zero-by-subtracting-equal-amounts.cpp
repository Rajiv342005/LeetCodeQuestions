class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>used;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                used.insert(nums[i]);
            }
            else continue;
        }
        return used.size();
    }
};