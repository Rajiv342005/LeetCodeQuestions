class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size());
        int num = 0;

        for (int i = 0; i < nums.size(); i++) {
            num = (num * 2 + nums[i]) % 5;
            ans[i] = (num == 0);
        }

        return ans;
    }
};