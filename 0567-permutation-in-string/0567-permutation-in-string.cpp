class Solution {
public:
    bool check(vector<int>&first,vector<int>&second){
        for(int i=0;i<26;i++){
            if(first[i]!=second[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>s1T(26,0);
        vector<int>s2T(26,0);
        int shrinkPointer = 0;
        int expandPointer = 0;
        int n = s2.size();
        for(char ch:s1){
            s1T[ch-'a']++;
        }
        int windowSize;
        while(expandPointer<n){
            s2T[s2[expandPointer]-'a']++;
            windowSize = expandPointer-shrinkPointer+1;
            if(windowSize==s1.size()){
                if(check(s1T,s2T)) return true;
                s2T[s2[shrinkPointer]-'a']--;
                shrinkPointer++;
            }
            expandPointer++;
        }
        return false;
    }
};