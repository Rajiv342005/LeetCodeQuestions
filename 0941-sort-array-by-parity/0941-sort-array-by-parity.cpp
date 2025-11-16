class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans;
        for(int &val:nums){
            if(val%2==0){
                ans.push_back(val);
            }
            else continue;
        }
        for(int &val:nums){
            if(val%2!=0){
                ans.push_back(val);
            }
            else continue;
        }
        return ans;
    }
};