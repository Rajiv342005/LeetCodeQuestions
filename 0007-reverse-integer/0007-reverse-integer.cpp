class Solution {
public:
    int reverse(int x) {
        long long num = abs((long long)x);
        long long number = 0;
        int rem  =0;
        while(num>0){
            rem = num%10;
            number = number*10+rem;
            num = num/10;
        }
        if(x<0) number = -number;
        if (number > INT_MAX || number < INT_MIN)
            return 0;
        return (int)number;
        
    }
};