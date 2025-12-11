class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int low=INT_MAX;
        int high = INT_MIN;
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(nums[i]>high) high = nums[i];
            if(nums[i]<low) low = nums[i];
        }
        for(int i=low;i<=high;i++){
            if(m.count(i)){
                continue;
            }
            else ans.push_back(i);
        }
        return ans;
    }
};