class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGcd(n);
        int mxi = INT_MIN;
        for(int i=0;i<n;i++){
            mxi = max(mxi,nums[i]);
            prefixGcd[i] = gcd(nums[i],mxi);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long sum = 0;
        int start = 0;
        int end = n-1;
        while(start<end){
            sum += gcd(prefixGcd[start],prefixGcd[end]);
            start++;
            end--;
        }
        return sum;
    }
};