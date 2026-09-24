class Solution {
public:
    int countSubarray(vector<int>&nums,int k){
        if(k<0) return 0;
        unordered_map<int,int>freq;
        int shrinkPointer = 0;
        int expandPointer = 0;
        int countSubarray = 0;
        while(expandPointer<nums.size()){
            freq[nums[expandPointer]]++;
            if(freq.size()>k){
                while(freq.size()>k){
                    if(freq[nums[shrinkPointer]]==1) freq.erase(nums[shrinkPointer]);
                    else freq[nums[shrinkPointer]]--;
                    shrinkPointer++;
                }
            }
            countSubarray += (expandPointer-shrinkPointer+1);
            expandPointer++;
        }
        return countSubarray;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int noOfSubarray1 = countSubarray(nums,k);
        int noOfSubarray2 = countSubarray(nums,k-1);
        return noOfSubarray1 - noOfSubarray2; 
    }
};