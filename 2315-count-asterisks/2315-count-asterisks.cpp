class Solution {
public:
    int countAsterisks(string s) {
        bool isAsteric = false;
        int countAsteric = 0;
        for(auto ch:s){
            if(ch=='|'){
                isAsteric = !isAsteric;
            }
            else if(ch=='*'){
                if(!isAsteric)
                countAsteric++; 
            }
        }
        return countAsteric;
    }
};