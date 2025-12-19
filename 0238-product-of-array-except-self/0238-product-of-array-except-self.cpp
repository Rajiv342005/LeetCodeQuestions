class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>suffix;
        int suffi=1;
        int pref=1; 
        for(int i=nums.size()-1;i>=0;i--){
            suffix.push_back(suffi);
            suffi*=nums[i];
        }
        reverse(suffix.begin(),suffix.end());
        for(int i=0;i<nums.size();i++){
            suffix[i]*=pref;
            pref*=nums[i];
        }
        return suffix;
    }
};