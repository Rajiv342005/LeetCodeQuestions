class Solution {
public:
    int countSegments(string s) {
        int index=0;
        string word= "";
        // vector<string>ans; 
        int count =0;
        while(index<s.size()){
            while(index<s.size() && s[index]!=' '){
                word+=s[index++];
            }
            // if(word!="") ans.push_back(word); 
            if(word!="") count++; 
            word = "";
            index++;
        }
        // return ans.size();
        return count;
    }
};