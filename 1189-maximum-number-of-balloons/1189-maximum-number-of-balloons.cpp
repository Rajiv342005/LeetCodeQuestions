class Solution {
public:
    bool check(char ch,int freq,unordered_map<char,int>&mp){
        if(ch=='l' || ch=='o'){
            freq = freq/2;
        }
        for(auto it:mp){
            if(it.first=='l' || it.first=='o'){
                int occur = 2*freq;
                if(occur>it.second) return false;
            }
            else{
                if(freq>it.second) return false;
            }
        }
        return true;
    }
    int maxNumberOfBalloons(string text) {
        unordered_set<char>alpha = {'b','a','l','o','n'};
        unordered_map<char,int>freq;
        for(char ch:alpha){
            freq[ch] = 0;
        }
        for(auto ch: text){
            if(alpha.count(ch))
            freq[ch]++;
        }
        int count = 0;
        for(auto it:freq){
            if(check(it.first,it.second,freq)){
                if(it.first!='l' && it.first!='o'){
                    count = max(count,it.second);
                }
                else count = max(count,it.second/2);
            }
        }
        return count;
    }
};