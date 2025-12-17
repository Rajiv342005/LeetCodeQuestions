class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int prefixsum=0;
        int count=0;
        m[0] =1;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            if(m.find(prefixsum-k)!=m.end()){
                count+=m[prefixsum-k];
            }
            m[prefixsum]++;
        }
        return count;
    }
};