class Solution {
public:
    int countNiceSubarray(vector<int>&nums,int k){
        if(k<0) return 0;
        int shrinkPointer = 0;
        int expandPointer = 0;
        int totalCount = 0;
        int currentSum = 0;
        while(expandPointer<nums.size()){
            currentSum += (nums[expandPointer]%2);
            if(currentSum>k){
                while(currentSum>k){
                    currentSum -= (nums[shrinkPointer])%2;
                    shrinkPointer++;
                }
            }
            totalCount += (expandPointer-shrinkPointer+1);
            expandPointer++;
        }
        return totalCount;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count1 = countNiceSubarray(nums,k);
        int count2 = countNiceSubarray(nums,k-1);
        return count1-count2;
    }
};