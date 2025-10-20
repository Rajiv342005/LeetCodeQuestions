class Solution {
public:
    int finalValueAfterOperations(vector<string>& nums) {
        int num =0; int index=0;
        while(index<nums.size()){
            if(nums[index]=="X++" || nums[index]=="++X"){
                num++; index++;
            }
            else{
                num--; index++;
            }
        }
        return num;
    }
};