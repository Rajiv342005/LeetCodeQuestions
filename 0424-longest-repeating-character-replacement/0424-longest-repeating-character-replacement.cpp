class Solution {
public:
    int CountReplacement(vector<int>&nums,int target){
        int maxValue = INT_MIN;
        for(int val:nums){
            maxValue = max(maxValue,val);
        }
        return target-maxValue;
    }
    int characterReplacement(string s, int k) {
        int shrinkPointer = 0;
        int expandPointer = 0;
        int maxLength = 0;
        vector<int>freq(26,0);
        int n = s.size();
        int currReplacement;
        while(expandPointer<n){
            freq[s[expandPointer]-'A']++;
            currReplacement = CountReplacement(freq,expandPointer-shrinkPointer+1);
            if(currReplacement<=k)
            maxLength = max(maxLength,expandPointer-shrinkPointer+1);
            else{
                while(shrinkPointer<expandPointer && currReplacement>k){
                    freq[s[shrinkPointer]-'A']--;
                    shrinkPointer++;
                    currReplacement = CountReplacement(freq,expandPointer-shrinkPointer+1);
                }
            }
            expandPointer++;
        }
        return maxLength;
    }
};