class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lowercase(26,-1);
        vector<int>uppercase(26,-1);
        vector<bool>visited(26,0);
        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                lowercase[word[i]-'a'] = i;
            }
            else{
                if(uppercase[word[i]-'A']==-1){
                    uppercase[word[i]-'A'] = i;
                }
            }
        }
        int specialCharacter = 0;
        for(auto ch:word){
            if(islower(ch)){
                if(visited[ch-'a']==0){
                   visited[ch-'a']=1;
                   if(lowercase[ch-'a']==-1 || uppercase[ch-'a']==-1) continue;
                   if(lowercase[ch-'a']!=-1 && uppercase[ch-'a']!=-1 && lowercase[ch-'a']<uppercase[ch-'a'])
                   specialCharacter++;
                }
            }
            else{
                if(visited[ch-'A']==0){
                    visited[ch-'A']=1;
                    if(lowercase[ch-'A']==-1 || uppercase[ch-'A']==-1) continue;
                    if(lowercase[ch-'A']!=-1 && uppercase[ch-'A']!=-1 && lowercase[ch-'A']<uppercase[ch-'A'])
                    specialCharacter++;
                    // else
                    // if(specialCharacter==0) return 0;
                }
            }
        }
        return specialCharacter;
    }
};