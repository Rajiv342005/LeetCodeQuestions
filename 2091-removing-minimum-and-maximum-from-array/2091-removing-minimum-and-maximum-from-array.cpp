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
        int bothleft = std::max(minl,maxl);
        int bothright = std::max(minr,maxr);
        int ans = std::min({bothleft, minl + maxr, minr + maxl,bothright});
        return ans;     
    }
};