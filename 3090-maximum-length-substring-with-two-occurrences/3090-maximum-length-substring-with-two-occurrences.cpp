class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxlen = 0;
        int start = 0;
        int pointer = 0;
        vector<int>freq(26,0);
        while(pointer<s.size()){
            int idx = s[pointer]-'a';
            if(freq[idx]==2){
                while(start<pointer && s[start]!=s[pointer]){
                    freq[s[start]-'a']--;
                    start++;
                }
                start++;
            }
            else{
                freq[idx]++;
            }
            maxlen = max(maxlen,pointer-start+1);
            pointer++;
        }
        return maxlen;
    }
};