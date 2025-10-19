class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum=0;
        int rightsum=0;
        int pivot=0;
        for(int i=0;i<nums.size();i++){
            rightsum+=nums[i];
        }
        while(pivot<nums.size()){
            if(pivot>=1) leftsum+=nums[pivot-1];
            rightsum-=nums[pivot];
            if(leftsum == rightsum ) return pivot;
            else pivot++;
        }
        return -1;

    }
};