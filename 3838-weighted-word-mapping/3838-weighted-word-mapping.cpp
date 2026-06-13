class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto word:words){
            int weight =0;
            for(auto ch:word){
                weight+= weights[ch-'a'];
            }
            weight = weight%26;
            ans+= (26-weight-1)+'a';
        }
        return ans;
    }
};