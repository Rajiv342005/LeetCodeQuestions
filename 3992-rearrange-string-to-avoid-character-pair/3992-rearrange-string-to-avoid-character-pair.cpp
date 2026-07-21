class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int freqX = 0;
        int freqY = 0;
        for(auto ch:s){
            if(ch==x) freqX++;
            else if(ch==y) freqY++;
        }
        string ans = "";
        for(int i=0;i<freqY;i++){
            ans+=y;
        }
        for(int i=0;i<freqX;i++){
            ans+=x;
        }
        for(auto ch:s){
            if(ch==x || ch==y) continue;
            ans +=ch;
        }
        return ans;
    }
};