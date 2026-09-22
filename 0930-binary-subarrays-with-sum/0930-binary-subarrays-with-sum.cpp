class Solution {
public:
    int CountSubarray(vector<int>&nums,int goal){
        if(goal<0) return 0;
        int shrinkPointer = 0;
        int expandPointer = 0;
        int count = 0;
        int currSum = 0;
        while(expandPointer<nums.size()){
            currSum += nums[expandPointer];
            if(currSum>goal){
                while(currSum>goal){
                    currSum -= nums[shrinkPointer];
                    shrinkPointer++;
                }
            }
            count += (expandPointer-shrinkPointer+1);
            expandPointer++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count1   =  CountSubarray(nums,goal);
        int count2   =  CountSubarray(nums,goal-1);
        return count1-count2;     
    }
};