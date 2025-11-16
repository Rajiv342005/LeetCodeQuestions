class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
       vector<int>ans(nums.size(),0);
       int pointer1=0;
       int pointer2=1;
       for(int &val:nums){
        if(val%2==0){
            ans[pointer1] = val;
            pointer1+=2;
        }
        else{
            ans[pointer2] = val;
            pointer2+=2;
        }
       } 
       return ans;
    }
};