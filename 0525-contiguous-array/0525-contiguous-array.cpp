class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        int currSum = 0;
        unordered_map<int,int>used;
        used[0] = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]) currSum++;
            else currSum--;
            if(used.count(currSum)){
                maxLength = max(maxLength,i-used[currSum]);
            }
            else used[currSum] = i;   
        }
        return maxLength;
    }
};