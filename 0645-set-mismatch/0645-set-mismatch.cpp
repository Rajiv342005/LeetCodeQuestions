class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int>used;
        int rep = -1;
        for(int i=0;i<nums.size();i++){
            if(used.count(nums[i])){
                rep = nums[i];
            }
            else used.insert(nums[i]);
        }
        int mis = -1;
        for(int i=1;i<=nums.size();i++){
            if(!used.count(i)) mis = i;
        }
        return {rep,mis};
    }
};