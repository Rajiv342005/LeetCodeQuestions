class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n = nums.size();
        int peak = 0;
        int valley = 0;
        for(int i=1; i<n-1; i++){
            // Check for Peak 
            if((nums[i]>nums[i - 1]) && (nums[i] > nums[i + 1])) peak += nums[i];
            // Check for Valley
            if((nums[i] < nums[i - 1]) && (nums[i] < nums[i + 1])) valley+= nums[i];
        }
        return peak-valley;    
    }
};