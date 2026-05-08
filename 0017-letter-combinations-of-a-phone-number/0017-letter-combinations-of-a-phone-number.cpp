class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        unordered_map<int,string>lc = {
            {2,"abc"},
            {3,"def"},
            {4,"ghi"},
            {5,"jkl"},
            {6,"mno"},
            {7,"pqrs"},
            {8,"tuv"},
            {9,"wxyz"}
        };
        vector<string>temp(lc[digits[0]-'0'].size(),"");
        int idx =0;
        for(auto ch:lc[digits[0]-'0']){
            temp[idx++].push_back(ch);
        }
        vector<string>currans;
        for(int i=1;i<digits.size();i++){
            currans.clear();
            for(auto ch:lc[digits[i]-'0']){
                for(int i=0;i<temp.size();i++){
                    string s = temp[i];
                    s.push_back(ch);
                    currans.push_back(s);
                }
            }
            temp = currans;
        }
        return temp;
    }
};