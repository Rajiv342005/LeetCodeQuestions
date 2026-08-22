class Solution {
public:
    int digitSum(int num){
        if(num==0) return 0;
        return num%10 + digitSum(num/10);
    }
    int digitProduct(int num){
        if(num==0) return 1;
        return (num%10)*digitProduct(num/10);
    }
    bool checkDivisibility(int n) {
        int sum = digitSum(n);
        int product = digitProduct(n);
        int totalSum = sum+product;
        return n%totalSum==0;
    }
};