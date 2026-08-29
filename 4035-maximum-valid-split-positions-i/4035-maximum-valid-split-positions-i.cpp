class Solution {
public:
    int findMaxSplit(vector<int>&nums){
        int score = 0;
        vector<int>suffixGCD(nums.size());
        vector<int>prefixGCD(nums.size());
        int g = nums[0];
        for(int i=0;i<nums.size();i++){
            g = gcd(g,nums[i]);
            prefixGCD[i] = g;
        }
        g = nums.back();
        for(int i=nums.size()-1;i>=0;i--){
            g = gcd(g,nums[i]);
            suffixGCD[i] = g;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(prefixGCD[i]==suffixGCD[i+1]) score++;
        }
        return score;
    }
    int maxValidSplits(vector<int>& nums) {
        int maxScore = INT_MIN;
        for(int i=0;i<nums.size();i++){
            vector<int>nums1 = nums;
            nums1.erase(nums1.begin()+i);
            maxScore = max(maxScore,findMaxSplit(nums1));
        }
        maxScore = max(maxScore,findMaxSplit(nums));
        return maxScore;
    }
};