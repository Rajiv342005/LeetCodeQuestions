class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int first =0;
        int second =0;
        int final1;
        // Skipping First House;
        for(int i=n-1;i>=1;i--){
            final1 = max(first,second+nums[i]);
            second = first;
            first = final1;
        }
        // Skipping Last House;
        int final2;
        first=second =0;
        for(int i=n-2;i>=0;i--){
            final2 = max(second+nums[i],first);
            second = first;
            first = final2;
        }
        return max(final1,final2);
    }
};