class Solution {
public:
    bool checkString(string s) {
        bool checkb = false;
        for(char ch: s){
            if(ch == 'a'){
                if(checkb) return false;
            }
            else checkb = true;
        }
        return true;
    }
};