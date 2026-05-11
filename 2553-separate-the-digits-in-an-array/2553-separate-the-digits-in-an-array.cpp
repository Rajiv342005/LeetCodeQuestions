class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto val:nums){
            string s = to_string(val);
            for(auto ch:s){
                ans.push_back(ch-'0');
            }

        }
        return ans;
    }
};