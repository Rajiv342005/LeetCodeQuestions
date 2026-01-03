class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        set<int>used(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(used.count(nums[i]+diff) && used.count(nums[i]+2*diff)){
                count++;
            }
            else continue;
        }
        return count;
    }
};