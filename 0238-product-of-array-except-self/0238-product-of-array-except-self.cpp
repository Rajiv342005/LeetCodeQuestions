class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>suffix;
        vector<int>prefix;
        int suffi=1;
        int pref=1; 
        for(int i=nums.size()-1;i>=0;i--){
            suffix.push_back(suffi);
            suffi*=nums[i];
        }
        reverse(suffix.begin(),suffix.end());
        for(int i=0;i<nums.size();i++){
            prefix.push_back(pref);
            pref*=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            prefix[i]*=suffix[i];
        }
        return prefix;
    }
};