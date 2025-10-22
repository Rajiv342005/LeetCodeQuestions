class Solution {
public:
    string toLowerCase(string s) {
       int index =0;
       int count =0;
       while(index<s.size()) {
        if(s[index]>='A'&&s[index]<='Z'){
        count = s[index]-'A';
        char s1 = 'a'+count;
        s[index] = s1;
        }
        index++;
       }
       return s;
    }
};