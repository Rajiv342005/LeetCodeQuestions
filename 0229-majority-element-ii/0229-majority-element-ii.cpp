class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(const auto &pair:m){
            if(pair.second>nums.size()/3){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};