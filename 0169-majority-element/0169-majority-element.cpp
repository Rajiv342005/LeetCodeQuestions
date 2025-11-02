class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int last =nums[0];
        int index =0;
        while(index<nums.size()){
            while(index<nums.size()&&nums[index]==last){
                count++;
                index++;
            }
            if(count>(nums.size()/2)) return last;
            last = nums[index];
            count =0;
        }
        return -1;
    }
};