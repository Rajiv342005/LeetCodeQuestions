class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int repeat=0;
        int missing=0; bool present=false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) repeat=nums[i];
        }
        for(int j=1;j<=nums.size();j++){
            present = false;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==j){
                    present = true;
                    break;
                }
            }
            if(!present) missing = j;
        }
        return {repeat,missing};
    }
};