class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int shrinkPointer = 0;
        int expandPointer = 0;
        int windowSum = 0;
        int n = nums.size();
        int minSubarray = INT_MAX;
        while(expandPointer<n){
            windowSum += nums[expandPointer];
            if(windowSum>=target){
                while(shrinkPointer<=expandPointer && windowSum>=target){
                    minSubarray = min(minSubarray,expandPointer-shrinkPointer+1);
                    windowSum -= nums[shrinkPointer];
                    shrinkPointer++;
                }
            }
            expandPointer++;
        }
        return minSubarray==INT_MAX?0:minSubarray;
    }
};