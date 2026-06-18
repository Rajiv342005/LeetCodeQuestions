class Solution {
public:
    long long removeZeros(long long n) {
        long long mul = 1;
        long long num = 0;
        while(n>0){
            int digit = n%10;
            if(digit==0){
                n = n/10;
                continue;
            }
            num = (mul*digit)+num;
            mul = mul*10;
            n = n/10; 
        }
        return num;
    }
};