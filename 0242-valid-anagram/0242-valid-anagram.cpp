class Solution {
public:
    bool IsValidAnagrams(vector<int>sTable,vector<int>tTable){
        for(int i=0; i<26; i++){
            if(sTable[i]!=tTable[i]) return false;
        }
        return true;
    }
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m) return false;
        vector<int>sTable(26,0);
        vector<int>tTable(26,0);
        for(char ch: s) sTable[ch-'a']++;
        for(char ch: t) tTable[ch-'a']++;
        return IsValidAnagrams(sTable,tTable);
    }
};