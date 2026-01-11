class Solution {
public:
    string reverseWords(string s) {
        int pointer1=0;
        int pointer2=0;
        while(pointer2<s.size()){
            if(s[pointer2]==' '){
                reverse(s.begin()+pointer1,s.begin()+pointer2);
                pointer1=pointer2+1;
            }
            pointer2++;
        }
        reverse(s.begin()+pointer1,s.end());
        return s;   
    }
};