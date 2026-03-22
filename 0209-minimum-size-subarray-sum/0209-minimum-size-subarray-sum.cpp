class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen = INT_MAX;
        int start=0;
        int sum =0;
        int index=0;
        while(index<nums.size()){
            sum+=nums[index];
            if(sum>=target){
                minlen = min(minlen,index-start+1);
            }
            while(sum>=target && start<index){
                sum-=nums[start++];
                if(sum>=target){
                minlen = min(minlen,index-start+1);
                }
            }
            index++;
        }
        if(minlen==INT_MAX) minlen=0;
        return minlen;   
    }
};