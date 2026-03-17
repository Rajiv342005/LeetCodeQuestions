class Solution {
public:
    int reverseBits(int n) {
        int num=0;
        vector<int>bit(32,0);
        int counter =31;
        while(n>0){
            int rem = n%2;
            bit[counter--]=rem;
            n = n/2;
        }
        for(int i=31;i>=0;i--){
            num = num*2+bit[i];
        }
        return num;
    }
};