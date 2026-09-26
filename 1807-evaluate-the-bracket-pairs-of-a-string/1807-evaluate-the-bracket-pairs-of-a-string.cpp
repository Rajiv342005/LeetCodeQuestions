class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(vector<string> element: knowledge){
            string key = element[0];
            string value = element[1];
            mp[key] = value;
        }
        int index = 0;
        int startidx,endidx;
        string ans = "";
        while(index<s.size()){
            if(s[index]=='('){
                startidx = index+1;
                while(index<s.size() && s[index]!=')'){
                    index++;
                }
                endidx = index;
                string key = s.substr(startidx,endidx-startidx);
                if(mp.count(key)){
                    ans += mp[key];
                }
                else ans += '?';
            }
            else{
                ans += s[index]; 
            }
            index++;
        }
        return ans;
    }
};