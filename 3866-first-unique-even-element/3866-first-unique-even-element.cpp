class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>used;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                used[nums[i]]++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0 && used[nums[i]]==1){
                return nums[i];
            }
        }
        return -1;
    }
};