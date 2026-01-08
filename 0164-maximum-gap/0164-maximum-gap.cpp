class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        sort(nums.begin(),nums.end());
        int MaxDiff=0;
        for(int i=0;i<nums.size()-1;i++){
            if((nums[i+1]-nums[i])>MaxDiff){
                MaxDiff = nums[i+1]-nums[i];
            }
        }
        return MaxDiff;   
    }
};