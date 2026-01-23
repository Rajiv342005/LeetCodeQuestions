class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>used;
        for(int i=0;i<nums.size();i++){
            used.insert(nums[i]);
        }
        int num =0;
        for(int i=0;i<=nums.size();i++){
            num+=k;
            if(used.count(num)) continue; 
            else return num;
        }
        return num;
    }
};