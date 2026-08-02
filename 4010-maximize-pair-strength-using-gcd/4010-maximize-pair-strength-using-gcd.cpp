class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long MaxStrength = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long mul = 1LL*nums[i]*nums[j];
                int GCD = gcd(nums[i],nums[j]);
                long long div = 1LL*GCD*GCD;
                MaxStrength = max(MaxStrength,mul/div);
            }
        }
        return MaxStrength;
    }
};