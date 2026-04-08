class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++){
            int start =queries[i][0];
            int end = queries[i][1];
            int inc =  queries[i][2];
            int mul = queries[i][3];
            for(int k=start;k<=end;k+=inc){
                long long prd = (1LL*nums[k]%(1000000007)*mul)%1000000007;
                nums[k] = prd;
            }
        }
        int bitwiseXOR =nums[0];
        for(int i=1;i<nums.size();i++){
            bitwiseXOR = bitwiseXOR^nums[i];
        }
        return bitwiseXOR;
    }
};