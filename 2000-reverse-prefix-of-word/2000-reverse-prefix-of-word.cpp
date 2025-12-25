class Solution {
public:
    string reversePrefix(string word, char ch) {
        int num =0;
        bool pres = false;
        int index=0;
        while(index<word.size()){
            if(word[index]==ch){
                num = index;
                pres = true;
                break;
            }
            index++;
        }
        string s = word;
        if(pres){
            reverse(s.begin(),s.begin()+num+1);
        }
        return s;
    }
};