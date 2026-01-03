class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxval = 0;
        vector<int>prefixMax(nums.size());
        vector<int>postfixMax(nums.size());
        prefixMax[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefixMax[i] = max(prefixMax[i-1],nums[i]);
        }
        postfixMax[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            postfixMax[i] = max(postfixMax[i+1],nums[i]);
        }
        for(int j=1;j<nums.size()-1;j++){
            int right = postfixMax[j+1];
            int left =prefixMax[j-1];
            if(left>nums[j]){
                maxval = max(maxval,1LL*(left-nums[j])*right);
            } 
        }
        return maxval;
    }
};