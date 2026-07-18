class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for(auto val:nums){
            minNum = min(minNum,val);
            maxNum = max(maxNum,val);
        }
        return gcd(minNum,maxNum);
    }
};