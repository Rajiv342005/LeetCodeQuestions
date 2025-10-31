class Solution {
public:
    string reverseVowels(string s) {
        unordered_set <char> pre = {'A','a','E','e','I','i','O','o','U','u'};
        int pointer1=0;
        int pointer2 =s.size()-1;
        // char temp = 'a';
        while(pointer1<pointer2){
            if(pre.count(s[pointer1])&&pre.count(s[pointer2])){
                // temp = s[pointer1];
                // s[pointer1] = s[pointer2];
                // s[pointer2]=temp;
                swap(s[pointer1],s[pointer2]);
                pointer1++,pointer2--;
            }
            else if(!pre.count(s[pointer1])&&pre.count(s[pointer2])){
                pointer1++;
            }
            else pointer2--;
        }
        return s;
    }
};