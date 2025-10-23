class Solution {
public:
    string convertToBase7(int num2) {
        if(num2==0) return "0";
        int num = num2;
        if(num<0) num = abs(num);
        int digit =0;
        string s="";
        while(num>0){
            digit = num%7;
            s+=(digit+'0');
            num = num/7;
        }
        if(num2!=abs(num2)) {
            s+='-';
        }
        reverse(s.begin(),s.end());
        return s;
        

    }
};