class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            if(m.count(s[i])){
                return s[i];
            }
            else m[s[i]]++;
        }
        return 'a';
    }
};