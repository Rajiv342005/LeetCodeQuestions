class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>nums(26,0);
        for(int i=0;i<chars.size();i++){
            nums[chars[i]-'a']++;
        }
        int sum=0;
        bool pres = true;
        for(int i=0;i<words.size();i++){
            pres = true;
            vector<int>check = nums;
            for(int j=0;j<words[i].size();j++){
                if(check[words[i][j]-'a']==0) pres = false;
                else check[words[i][j]-'a']--;
            }
            if(pres) sum+=words[i].size();
            else continue;
        }
        return sum;
    }
};