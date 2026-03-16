class Solution {
public:
    bool isPalindrome(string s) {
        int start =0;
        int end =s.size()-1;
        while(start<end){
             if(isalnum(s[start])&&isalnum(s[end])){
                auto d1 = tolower(s[start]);
                auto d2 = tolower(s[end]);
                if(d1==d2){
                    start++;
                    end--;
                }
                else{
                    return false;
                } 
             }
             else{
                if(!isalnum(s[start])) start++;
                else if(!isalnum(s[end])) end--;
                else{
                    start++;
                    end--;
                }
             }
        }
        return true;
    }
};