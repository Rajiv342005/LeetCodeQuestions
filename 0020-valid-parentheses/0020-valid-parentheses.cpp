class Solution {
public:
    bool isValid(string s) {
        stack <char> s2;
        int index =0;
        while(index<s.size()){
            if(s[index]=='{' || s[index]=='[' || s[index]=='('){
                s2.push(s[index]);
                index++;
            }
            else if(!s2.empty()){
                if((s2.top()=='(' && s[index]==')')||(s2.top()=='{' && s[index]=='}')||(s2.top()=='[' && s[index]==']')){
                    s2.pop();
                    index++;
                }
                else return false;
            }
            else return false;
        }
        return s2.empty();
    }
};