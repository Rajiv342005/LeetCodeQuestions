class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int min=0;
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums[min]) min = i;
            if(nums[i]>nums[max]) max = i;
        }
        int minl=min+1;
        int minr=nums.size()-min;
        int maxl=max+1;
        int maxr=nums.size()-max;
        int max2 = std::max(minl,maxl);
        int min2 = std::max(minr,maxr);
        int ans = std::min({minl + maxl, minl + maxr, minr + maxl, minr + maxr,max2,min2});
        return ans;     
    }
};