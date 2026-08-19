class Solution {
public:
    int findComplement(int num) {
        string bn = "";
        while(num>0){
            bn += num%2+'0';
            num /= 2;
        }
        reverse(bn.begin(),bn.end());
        int cpt = 0;
        for(char ch:bn){
            if(ch=='1')
            cpt = cpt*2;
            else
            cpt = cpt*2+1;
        }
        return cpt;
    }
};