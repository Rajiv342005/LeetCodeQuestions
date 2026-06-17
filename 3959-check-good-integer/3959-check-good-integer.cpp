class Solution {
public:
    bool checkGoodInteger(int n) {
        long long digitSum = 0;
        long long SquareSum = 0;
        while(n>0){
            int digit = n%10;
            digitSum += digit;
            SquareSum += (digit*digit);
            n = n/10;
        }
        return (SquareSum-digitSum)>=50;
    }
};