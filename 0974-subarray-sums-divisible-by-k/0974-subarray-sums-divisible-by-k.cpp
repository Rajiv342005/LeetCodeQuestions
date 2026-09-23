class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int totalCount = 0;
        int currentSum = 0;
        int n = nums.size();
        vector<int>freq(k,0);
        freq[0] = 1;
        for(int val: nums){
            currentSum += val;
            currentSum %= k;
            if(currentSum<0) currentSum += k;
            if(freq[currentSum]) totalCount += freq[currentSum];
            freq[currentSum]++; 
        }
        return totalCount;
    }
};