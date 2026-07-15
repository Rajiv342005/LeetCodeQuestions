class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // Sum of first 2n Natural Number.
        int sumTotal = ((2*n)*(2*n+1))/2;
        // Sum of first n Even Natural Number.
        int sumEven = (n)*(n+1);
        int sumOdd = sumTotal-sumEven;
        int largest = min(sumEven,sumOdd);
        for(int i=largest;i>=1;i--){
            if(sumEven%i==0 && sumOdd%i==0)
                return i;
        }
        return 1;
    }
};