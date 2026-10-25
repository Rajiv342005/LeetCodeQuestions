class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long totalCount = 0;
        int shrinkPointer = 0;
        int expandPointer = 0;
        int n = nums.size();
        while(expandPointer<n){
            if(nums[expandPointer]<minK || nums[expandPointer]>maxK){
                expandPointer += 1;
                shrinkPointer = expandPointer;
            }
            else{
                totalCount += (expandPointer-shrinkPointer+1);
                expandPointer++;
            }
        }
        return totalCount;
    }
};