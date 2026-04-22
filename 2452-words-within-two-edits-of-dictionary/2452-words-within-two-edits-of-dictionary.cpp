class Solution {
public:
    bool wordcheck(string word,string dict){
        if(word.size()!=dict.size()) return false;
        int count =0;
        for(int i=0;i<word.size();i++){
            if(word[i]!=dict[i]) count++;
        }
        return count<=2;   
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<dictionary.size();j++){
                if(wordcheck(queries[i],dictionary[j])){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};