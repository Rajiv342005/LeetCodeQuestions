class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i] - k))
                count += m[nums[i] - k];

            if(m.count(nums[i] + k))
                count += m[nums[i] + k];

            m[nums[i]]++;
        }
        return count;
    }
};
