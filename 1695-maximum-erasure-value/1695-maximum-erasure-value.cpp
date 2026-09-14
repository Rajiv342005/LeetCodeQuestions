class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int expandPointer = 0;
        int shrinkPointer = 0;
        unordered_set<int>used;
        int maxScore = INT_MIN;
        int n = nums.size();
        int currScore = 0;
        while(expandPointer<n){
            if(used.count(nums[expandPointer])){
                while(shrinkPointer<expandPointer && nums[shrinkPointer]!=nums[expandPointer]){
                    used.erase(nums[shrinkPointer]);
                    currScore -= nums[shrinkPointer];
                    shrinkPointer++;
                }
                shrinkPointer++;
            }
            else{
                currScore += nums[expandPointer];  
                used.insert(nums[expandPointer]);
                maxScore = max(maxScore,currScore);
            }
            expandPointer++;
        }
        return maxScore==INT_MIN?0:maxScore;
    }
};