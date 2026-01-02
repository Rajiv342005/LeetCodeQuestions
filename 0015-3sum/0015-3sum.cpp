class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int right = nums.size()-1;
            int left = i+1;
            while(left<right){
                int Sum = nums[right]+nums[left]+nums[i];
                if(Sum==0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    // skip duplicates for right
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if(Sum<0) left++;
                else right--;
            }     
        }
        return ans;
    }
};