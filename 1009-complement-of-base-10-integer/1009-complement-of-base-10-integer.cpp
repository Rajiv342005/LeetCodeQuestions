class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int counter =0;
        int exp=0;
        while(n>0){
            int rem = n%2;
            n/=2;
            if(rem==0){
                counter+= pow(2,exp);
            }
            exp++;
        }
        return counter;
    }
};