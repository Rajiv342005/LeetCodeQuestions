class Solution {
public:
    bool find(string &word,unordered_set<char>&row){
        for(auto ch:word){
            char c = tolower(ch);
            if(row.count(c)) continue;
            else return false;
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        unordered_set<char>row1 = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char>row2 = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char>row3 = {'z','x','c','v','b','n','m'};
        vector<string> ans;
        for(auto word:words){
            if(find(word,row1) || find(word,row2) || find(word,row3)) ans.push_back(word);
        }
        return ans;
    }
};