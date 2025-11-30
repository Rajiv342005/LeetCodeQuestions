class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool ispos = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                return 0;
            }
            else if(nums[i]<0){
                ispos = !ispos;
            }
            else{
               continue; 
            }
        } 
        if(ispos) return 1;
        return -1;
    }
};