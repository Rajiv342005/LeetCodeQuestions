class Solution {
public:
    int maxDistance(string moves) {
        int xmove = 0;
        int ymove = 0;
        int freemove = 0;
        for(auto ch:moves){
            if(ch=='U') ymove++;
            else if(ch=='D') ymove--;
            else if(ch=='L') xmove--;
            else if(ch=='R') xmove++;
            else freemove++;  
        }
        int ans = abs(xmove)+abs(ymove)+freemove;
        return ans;
    }
};