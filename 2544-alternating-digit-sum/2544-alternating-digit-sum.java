class Solution {
    public int alternateDigitSum(int n) {
        int sum = 0;
        int sign = 1;
        while(n > 0){
            int rem = n % 10;
            sum += rem*sign;
            sign *= -1;
            n /= 10;
        }
        return sign == 1 ? -sum : sum;
    }
}