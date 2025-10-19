class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
       int leftsum=0;
       int rightsum =0;
       for(int i=0;i<nums.size();i++){
        rightsum+=nums[i];
       }
       int index =0;
       while(index<nums.size()){
        if(index>=1) leftsum+=nums[index-1];
        rightsum -=nums[index];
        if(rightsum==leftsum) return index;
        else index++;
       } 
       return -1;
    }
};