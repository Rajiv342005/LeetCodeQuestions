class Solution {
public:
    bool judgeCircle(string moves) {
        int up=0;
        int right =0;
        for(char &dir:moves){
            if(dir=='U') up++;
            else if(dir=='D') up--;
            else if(dir=='R') right++;
            else right--;
        }
        return (up==0 && right==0);     
    }
};