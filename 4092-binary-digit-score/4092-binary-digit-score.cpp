class Solution {
public:
    int CalculateSetBit(int a){
        if(a==0) return 0;
        return a%2 + CalculateSetBit(a/2);
    }
    int calculateScore(int a, int b) {
        int s1 = CalculateSetBit(a);
        int s2 = CalculateSetBit(b);
        if(s1>=s2) return s1*s2;
        return s2/s1;
    }
};