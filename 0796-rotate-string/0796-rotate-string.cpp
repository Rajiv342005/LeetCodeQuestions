class Solution {
public:
    bool rotateString(string s, string goal) {
        int idx = 0;
        while(idx<s.size()){
            string s1 = s.substr(0,idx);
            string s2 = s.substr(idx);
            string sf = s2+s1;
            if(sf==goal) return true;
            idx++;
        }
        return false;
    }
};