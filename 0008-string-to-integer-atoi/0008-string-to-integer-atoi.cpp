class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        bool pos = true;
        bool start = false;
        for(auto ch:s){
            if(isdigit(ch)){
               int digit = ch - '0';
                if (num > INT_MAX / 10 || 
                   (num == INT_MAX / 10 && digit > 7)) {
                    return pos ? INT_MAX : INT_MIN;
                }
                num = num * 10 + digit;
                start = true;
            }
            else if(!start && isspace(ch)) continue;
            else if(!start && (ch=='+'|| ch=='-')){
                if(ch=='-') pos = false;
                start = true;
                continue;
            }
            else break;
        }
        if(!pos) return -num;
        return num;    
    }
};