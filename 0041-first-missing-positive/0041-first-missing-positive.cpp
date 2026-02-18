class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>used;
        for(int i=0;i<nums.size();i++){
            used.insert(nums[i]);
        }
        for(int i=1;i<=nums.size()+1;i++){
            if(used.find(i)!=used.end()) continue;
            else return i;
        }
        return 1;
    }
};