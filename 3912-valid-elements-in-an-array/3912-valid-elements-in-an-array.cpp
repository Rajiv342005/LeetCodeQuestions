class Solution {
public:
    bool leftcheck(vector<int>&nums,int index){
        for(int i=0;i<index;i++){
            if(nums[index]<=nums[i]) return false;
        }
        return true;
    }
    bool rightcheck(vector<int>&nums,int index){
        for(int i=index+1;i<nums.size();i++){
            if(nums[index]<=nums[i]) return false;
        }
        return true;
    }
    vector<int> findValidElements(vector<int>& nums) {
       vector<int>ans;
       for(int i=0;i<nums.size();i++){
        if(leftcheck(nums,i) || rightcheck(nums,i)){
            ans.push_back(nums[i]);
        }
        else continue;
       } 
       return ans;
    }
};