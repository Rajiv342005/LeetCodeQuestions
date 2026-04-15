class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int leftdist = INT_MAX;
        int rightdist = INT_MAX;
        int n = words.size();
        for(int i=startIndex;i<startIndex+n;i++){
            if(words[i%n]==target){
                rightdist = i-startIndex;
                break;
            }
        }
        for(int i=startIndex+n;i>startIndex;i--){
            if(words[i%n]==target){
                leftdist = abs(startIndex+n-i);
                break;
            }
        }
        if(leftdist==INT_MAX && rightdist==INT_MAX) return -1;
        return min(rightdist,leftdist);
    }
};