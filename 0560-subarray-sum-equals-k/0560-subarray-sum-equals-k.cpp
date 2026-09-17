class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currSum = 0;
        unordered_map<int,int>used;
        used[0]= 1;
        int countSubarray = 0;
        for(int val:nums){
            currSum += val;
            if(used.count(currSum-k)) countSubarray+= used[currSum-k];
            used[currSum]++;
        }
        return countSubarray;
    }
};