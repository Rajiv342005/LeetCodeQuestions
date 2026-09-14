class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int shrinkPointer = 0;
        int expandPointer = 0;
        int currCost = 0;
        int maxLength = INT_MIN;
        int n = s.size();
        while(expandPointer<n){
            currCost += abs(s[expandPointer]-t[expandPointer]);
            if(currCost<=maxCost){
                maxLength = max(maxLength,expandPointer-shrinkPointer+1);
            }
            else{
                while(shrinkPointer<=expandPointer && currCost > maxCost){
                    currCost -= abs(s[shrinkPointer]-t[shrinkPointer]);
                    shrinkPointer++;
                }
            }
            expandPointer++;
        }
        return maxLength==INT_MIN?0:maxLength;
    }
};