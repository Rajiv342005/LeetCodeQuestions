class Solution {
public:
    int maxDistinct(string s) {
        int maxlen = 0;
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            if(m.count(s[i])) continue;
            else{
                m[s[i]]++;
                maxlen++;
            }
        }
        return maxlen;     
    }
};