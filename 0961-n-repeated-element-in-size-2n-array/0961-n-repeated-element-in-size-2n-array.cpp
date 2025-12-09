class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int half = nums.size()/2;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]==half) return nums[i];
            else continue;
        }
        return -1;
    }
};