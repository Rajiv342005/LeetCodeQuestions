class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int indexi = -1;
        int indexj = -1;
        int prevProduct = INT_MIN;
        unordered_map<int,int>used;
        for(int i=0;i<nums.size();i++){
            int find = target - nums[i];
            if(find == nums[i]) continue;
            if(used.count(find)){
                int currProduct = find * nums[i];
                if(currProduct>prevProduct){
                    // Case No 1: when nums[i]>nums[j]
                    if(find>nums[i]){
                        indexi = used[find];
                        indexj = i;   
                    } 
                    // Case No 2: when nums[i]<nums[j]  
                    else{
                        indexj = used[find];
                        indexi = i;   
                    }
                    prevProduct = currProduct;
                }
                else continue;
            }
            used[nums[i]] = i;
        }
        return {indexi,indexj};
    }
};