class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char>used;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(!used.count(s[i])){
                used.insert(s[i]);
                count++;

            };
        }
        return count;
    }
};