class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maximum=0;
        int curr =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr++;
            }
            else{
                maximum = max(maximum,curr);
                curr =0;
            }
        }
        maximum = max(maximum,curr);
        return maximum;
    }
};