class Solution {
public:
    int countSegments(string s) {
        int index=0;
        string word= "";
        vector<string>ans;
        while(index<s.size()){
            while(index<s.size() && s[index]!=' '){
                word+=s[index++];
            }
            if(word!="") ans.push_back(word); 
            word = "";
            index++;
        }
        return ans.size();
    }
};