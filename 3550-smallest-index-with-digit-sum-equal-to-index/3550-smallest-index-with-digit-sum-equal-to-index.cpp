class Solution {
public:
    int digitSum(int n){
        if(n==0) return 0;
        return n%10 + digitSum(n/10);
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int ds = digitSum(nums[i]);
            if(ds==i) return i; 
        }
        return -1;
    }
};