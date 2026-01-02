class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>unique;
        sort(nums.begin(),nums.end());
        vector<int>v;

        for(int i=0;i<nums.size()-2;i++){
            int right = nums.size()-1;
            int left = i+1;
            while(left<right){
                int Sum = nums[right]+nums[left]+nums[i];
                if(Sum==0){
                    v = {nums[right],nums[left],nums[i]};
                    sort(v.begin(),v.end());
                    unique.insert(v);
                    left++;
                }
                else if(Sum<0) left++;
                else right--;
            }     
        }
        for(auto &x:unique){
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};