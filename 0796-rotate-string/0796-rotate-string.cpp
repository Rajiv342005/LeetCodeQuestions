class Solution {
public:
    bool rotateString(string s, string goal) {
        int idx = s.size();
        while(idx>0){
            char ch = s[0];
            s.erase(0,1);
            s.push_back(ch);
            if(s==goal) return true;
            idx--;
        }
        return false;
    }
};