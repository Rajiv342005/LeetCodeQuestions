class Solution {
public:
    int numberOfSubstrings(string s) {
        int totalsubstr = 0;
        int start=0;
        vector<int>freq(3,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            if(freq[0]>0 && freq[1]>0 && freq[2]>0){
                while(start<=i && freq[0]>0 && freq[1]>0 && freq[2]>0){
                    totalsubstr += (s.size()-i);
                    freq[s[start]-'a']--;
                    start++;
                }      
            }
        }
        return totalsubstr;
    }
};