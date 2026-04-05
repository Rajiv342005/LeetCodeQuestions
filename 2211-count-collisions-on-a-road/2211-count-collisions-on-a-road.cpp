class Solution {
public:
    int countCollisions(string directions) {
        int Collision =0;
        bool IsStatic = false;
        int countRight = 0;
        for(int i=0;i<directions.size();i++){
            if(countRight==0){
                if(directions[i]=='R') countRight++;
                else if(directions[i]=='S') IsStatic=true;
                else if(directions[i]=='L' && IsStatic) Collision++;
                else continue;
            }
            else{
                if(directions[i]=='R') countRight++;
                else if(directions[i]=='S'){
                    Collision+=countRight;
                    countRight =0;
                    IsStatic = true;
                }
                else{
                    Collision+=2;
                    Collision+= countRight-1;
                    countRight=0;
                    IsStatic = true;
                }
            }
        }
        return Collision;   
    }
};