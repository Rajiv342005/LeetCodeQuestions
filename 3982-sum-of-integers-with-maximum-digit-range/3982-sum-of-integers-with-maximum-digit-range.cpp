class Solution {
public:
    int DigitRange(int num){
        int largest = INT_MIN;
        int smallest = INT_MAX;
        while(num>0){
            int digit = num%10;
            largest = max(largest,digit);
            smallest = min(smallest,digit);
            num = num/10;
        }
        return largest-smallest;
    }
    int maxDigitRange(vector<int>& nums) {
        int MaxDigitRange = INT_MIN;
        unordered_map<int,int>used;
        for(int i=0;i<nums.size();i++){
            int digitRange  = DigitRange(nums[i]);
            used[nums[i]] = digitRange;
            MaxDigitRange = max(MaxDigitRange,digitRange);
        }
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(used[nums[i]]==MaxDigitRange) sum+=nums[i];
        }
        return sum;
    }
};