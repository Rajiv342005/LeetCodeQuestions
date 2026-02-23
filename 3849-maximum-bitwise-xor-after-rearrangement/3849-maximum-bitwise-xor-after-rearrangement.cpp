class Solution {
public:
    string maximumXor(string s, string t) {
        int count1 = 0;
        int count0 = 0;
        for(int i=0;i<t.size();i++){
            if(t[i]=='1') count1++;
            else count0++;
        }
        string s1 = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='1' && count0){
                s1+='1';
                count0--;
            }
            else if(s[i]=='0' && count1){
                s1+='1';
                count1--;
            }
            else s1+='0';
        }
        return s1;
    }
};