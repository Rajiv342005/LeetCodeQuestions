class Solution {
public:
    int numberOfSpecialChars(string word) {
        int counter =0;
        unordered_set<char>alpha;
        unordered_set<char>used;
        for(auto ch:word){
            if(islower(ch)){
                char cu = 'A'+(ch-'a');
                if(alpha.count(cu) && !used.count(cu)){
                    used.insert(ch);
                    used.insert(cu);
                    counter++;
                }
                else{
                    alpha.insert(ch);
                };
            }
            else{
                char cu = 'a'+(ch-'A');
                if(alpha.count(cu) && !used.count(cu)){
                    used.insert(ch);
                    used.insert(cu);
                    counter++;
                }
                else alpha.insert(ch);
            }
        }
        return counter;
    }
};