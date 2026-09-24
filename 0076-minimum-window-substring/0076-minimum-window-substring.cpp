class Solution {
public:
    int startidx = 0;
    bool check(vector<int>&a ,vector<int>&b){
        for(int i=0;i<a.size();i++){
            if(a[i]){
                if(a[i]>b[i]) return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int shrinkPointer = 0;
        int expandPointer = 0;
        int minLength = INT_MAX;
        int prevLength = minLength;
        vector<int>freqT(58,0);
        vector<int>freq(58,0);
        for(int i=0;i<t.size();i++) freqT[t[i]-'A']++;
        while(expandPointer<s.size()){
            freq[s[expandPointer]-'A']++;
            if(check(freqT,freq)){
                while(check(freqT,freq)){
                    minLength = min(minLength,expandPointer-shrinkPointer+1);
                    if(prevLength!=minLength){
                        prevLength = minLength;
                        startidx = shrinkPointer;
                    }
                    freq[s[shrinkPointer]-'A']--;
                    shrinkPointer++;
                }
            }
            expandPointer++;
        }
        if(minLength==INT_MAX) return "";
        return s.substr(startidx,minLength);     
    }
};