class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvgSubarray = INT_MIN;
        int windowSum = 0;
        for(int i=0;i<k;i++) windowSum+=nums[i];
        double avg = (windowSum)/(k*1.0);
        maxAvgSubarray = max(maxAvgSubarray,avg);
        for(int i=k;i<nums.size();i++){
            windowSum += nums[i];
            windowSum -= nums[i-k];
            avg = (windowSum)/(k*1.0);
            maxAvgSubarray = max(maxAvgSubarray,avg);
        }
        return maxAvgSubarray;
    }
};