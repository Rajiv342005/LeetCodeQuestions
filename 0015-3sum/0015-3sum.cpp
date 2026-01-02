class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        set<vector<int>>unique;
        unordered_set<int>used;
        for(int i=0;i<nums.size()-1;i++){
            used.clear();
            for(int j=i+1; j<nums.size();j++){
                int required = -(nums[i]+nums[j]);
                if(used.count(required)){
                    v = {nums[i],nums[j],required};
                    sort(v.begin(),v.end());
                    unique.insert(v);
                }
                used.insert(nums[j]);
            }
        }
        for(auto &x:unique){
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};