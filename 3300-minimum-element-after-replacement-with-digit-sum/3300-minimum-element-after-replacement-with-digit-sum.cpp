class Solution {
public:
    int DigitSum(int num){
        int digitsum = 0;
        while(num>0){
            digitsum += num%10;
            num/=10;
        }
        return digitsum;
    }
    int minElement(vector<int>& nums) {
        int minimumElement = INT_MAX;
        for(auto element:nums){
            int digitSum = DigitSum(element);
            minimumElement = min(minimumElement,digitSum);
        }
        return minimumElement;
    }
};