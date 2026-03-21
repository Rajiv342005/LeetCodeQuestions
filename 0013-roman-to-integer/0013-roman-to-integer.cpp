class Solution {
public:
    int romanToInt(string s) {
        int Number=0;
        int end = s.length();
        int index = 0;
        while(index<end){
            if(s[index]=='I'){
                if(s[index+1]=='V'){
                    Number+=4;
                    index+=2;
                }
                else if(s[index+1]=='X'){
                    Number+=9;
                    index+=2;
                }
                else{
                    Number++;
                    index+=1;
                }
            }
            if(s[index]=='V'){
                Number+=5;
                index+=1;
            }
            //condition for X
            if(s[index]=='X'){
                if(s[index+1]=='L'){
                    Number+=40;
                    index+=2;
                }
                else if(s[index+1]=='C'){
                    Number+=90;
                    index+=2;
                }
                else{
                    Number+=10;
                    index+=1;
                }
            }
            //condition for L
            if(s[index]=='L'){
                Number+=50;
                index+=1;
            }
            // condition for C
            if(s[index]=='C'){
                if(s[index+1]=='D'){
                    Number+=400;
                    index+=2;
                }
                else if(s[index+1]=='M'){
                    Number+=900;
                    index+=2;
                }
                else{
                    Number+=100;
                    index+=1;
                }
            }
            // Condition for D
            if(s[index]=='D'){
                Number+=500;
                index+=1;
            }
            //Condition for M
            if(s[index]=='M'){
                Number+=1000;
                index+=1;
            }
        }
        return Number;
    }
};