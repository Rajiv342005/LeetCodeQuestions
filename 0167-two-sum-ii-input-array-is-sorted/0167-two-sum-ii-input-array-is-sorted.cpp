class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int pointer1=0;
        int pointer2 =nums.size()-1;
        while(pointer1<pointer2){
            if(nums[pointer1]+nums[pointer2]>target){
                pointer2--;
            }
            else if(nums[pointer1]+nums[pointer2]<target){
                pointer1++;
            }
            else{
                return {pointer1+1,pointer2+1};
            }
        } 
        return {-1,-1};
    }
};