class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        // if(n==1) return nums[0];
        int freqMiddleElement = 0;
        int MiddleElement = nums[(n+1)/2-1];
        for(int i=0;i<n;i++){
            if(nums[i]==MiddleElement)
            freqMiddleElement++;
        }
        return freqMiddleElement==1;
    }
};