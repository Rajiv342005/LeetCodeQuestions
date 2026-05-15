class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimum = INT_MAX;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            minimum  = min(minimum,nums[mid]);
            // Sorted in Left Side.
            if(nums[low]<=nums[mid]){
                minimum  = min(minimum,nums[low]);
                low = mid+1;
            }
            // Sorted in Right Side.
            else high = mid-1;
        }
        return minimum;
    }
};