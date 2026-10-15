class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int SquareSum = 0;
        unordered_set<int>unique;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                unique.insert(nums[j]);
                int n = unique.size();
                SquareSum += (n*n);
            }
            unique.clear();
        }
        return SquareSum;
    }
};