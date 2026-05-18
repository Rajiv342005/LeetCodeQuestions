class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>prev = nums;
        int m = nums.size();
        for(int i=1;i<nums.size();i++){
            int ts = m-i;
            vector<int>temp(ts,0);
            for(int j=0;j<ts;j++){
                temp[j] = (prev[j]+prev[j+1])%10;
            }
            prev = temp;
        }
        return prev[0];    
    }
};