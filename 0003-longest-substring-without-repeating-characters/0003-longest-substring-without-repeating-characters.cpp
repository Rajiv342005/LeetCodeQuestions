class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        int currlength =0;
        unordered_set <char> used;
        int index =0;
        while(index<s.size()){
            if(used.find(s[index])!=used.end()){
                if(currlength>maxlength) maxlength=currlength;
                index = index - currlength + 1;
                used.clear();
                currlength = 0;
                continue;
            }
            else{
                    used.insert(s[index]);
                    currlength++;
                    index++;
                
            }
            if (currlength > maxlength) maxlength = currlength;
        }
        return maxlength;
    }
};