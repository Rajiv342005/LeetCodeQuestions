class Solution {
public:
    int countSubarray(vector<int>&nums,int k){
        if(k<=0) return 0;
        int shrinkPointer = 0;
        int expandPointer = 0;
        int totalCount = 0;
        int windowdistinct = 0;
        unordered_map<int,int>freq;
        while(expandPointer<nums.size()){
            freq[nums[expandPointer]]++;
            if(freq.size()>k){
                while(freq.size()>k){
                    if(freq[nums[shrinkPointer]]==1){
                        freq.erase(nums[shrinkPointer]);
                    }
                    else freq[nums[shrinkPointer]]--;
                    shrinkPointer++;
                }
            }
            totalCount += (expandPointer-shrinkPointer+1);
            expandPointer++;
        }
        return totalCount;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>used;
        for(int val: nums) used.insert(val);
        int totaldistinct = used.size();
        int count1 = countSubarray(nums,totaldistinct);
        int count2 = countSubarray(nums,totaldistinct-1);
        return count1-count2; 
    }
};