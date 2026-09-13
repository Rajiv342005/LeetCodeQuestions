class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int shrinkPointer = 0;
        int expandPointer = 0;
        int windowZero = 0;
        int maxOneIII = 0;
        int n = nums.size();
        while(expandPointer<n){
            if(nums[expandPointer]==0) windowZero++;
            if(windowZero<=k) maxOneIII = max(maxOneIII,expandPointer-shrinkPointer+1);
            if(windowZero>k){
                while(shrinkPointer<=expandPointer && windowZero>k){
                    if(nums[shrinkPointer]==0) windowZero--;
                    shrinkPointer++;
                }
            }
            expandPointer++;   
        }
        return maxOneIII;
    }
};