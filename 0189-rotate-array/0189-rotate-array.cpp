class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int index = nums.size()-1;
        if(k>=nums.size()){
            k = k%(index+1);
        }
        int start = index-k+1;
        vector<int>ans(index+1);
        int pointer1=0; int count=0;
        while(start<nums.size()){
            ans[count++] = nums[start++];
        }
        while(count<nums.size()){
            ans[count++] = nums[pointer1++];
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = ans[i];
        }   
    }
};