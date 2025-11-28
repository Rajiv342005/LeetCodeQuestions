class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(columnNumber==1) return "A";
        string ans = "";
        int num  = columnNumber;
        while(num>0){
            num--;
            int digit = num%26;
            ans.push_back(digit+'A');
            num = num/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};