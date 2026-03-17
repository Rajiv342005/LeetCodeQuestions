class Solution {
public:
    int hammingWeight(int n) {
        int counter =0;
        while(n>0){
            int num = n%2;
            if(num==1) counter++;
            n = n/2;
        }
        return counter;
    }
};