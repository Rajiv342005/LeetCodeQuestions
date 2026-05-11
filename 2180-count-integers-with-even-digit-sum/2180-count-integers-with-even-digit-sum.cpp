class Solution {
public:
    bool checkdigitsum(int N){
        int sum =0;
        string s = to_string(N);
        for(auto data:s){
            sum+= (data-'0');
        }
        return sum%2==0;
    }
    int countEven(int num) {
        int counter  =0;
        for(int i=1;i<=num;i++){
            if(checkdigitsum(i)) counter++;
        }
        return counter;
    }
};