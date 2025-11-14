class Solution {
public:
    int titleToNumber(string columnTitle) {
        int digit =0;
        int index = columnTitle.size()-1;
        int ans=0;
        int p =0;
        while(index>=0){
            digit = columnTitle[index]-'A'+1;
            ans = ans+ digit*pow(26,p++);
            index--;
        }
        return ans;    
    }
};