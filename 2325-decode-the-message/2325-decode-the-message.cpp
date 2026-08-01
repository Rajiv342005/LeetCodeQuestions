class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,int>table;
        int index = 0;
        for(char ch:key){
            if(ch==' ') continue;
            if(!table.count(ch)){
                table[ch] = index;
                index++;
            }
        }
        string plaintext = "";
        for(char ch: message){
            if(isalpha(ch)){
                plaintext.push_back(table[ch]+'a');
            }
            else plaintext.push_back(ch);
        }
        return plaintext;
    }
};