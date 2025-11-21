class Solution {
public:
    int search(vector<int>& nums, int target) {
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target){
        //         return i;
        //     }
        // }
        // return -1;

        int start=0;int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target) return mid;

            else if(nums[start]<=nums[mid]){
                if(nums[start]<=target && target<nums[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            
            }
            else{
                if(nums[start]>target && target>nums[mid]){
                    start=mid+1;
                }
                else end=mid-1;
            }
        }
        return -1;
    }
};