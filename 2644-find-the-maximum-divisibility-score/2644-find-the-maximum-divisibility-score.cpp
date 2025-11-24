class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        sort(divisors.begin(),divisors.end());
        int maxScore = divisors[0];
        int currcount=0;
        int prevcount=0;
        for(int i=0;i<divisors.size();i++){
            currcount =0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]%divisors[i]==0) currcount++;
                else continue;
            }
            if(currcount>prevcount){
                prevcount = currcount;
                maxScore = divisors[i];
            }
            else continue;
        }
        return maxScore;
    }
};