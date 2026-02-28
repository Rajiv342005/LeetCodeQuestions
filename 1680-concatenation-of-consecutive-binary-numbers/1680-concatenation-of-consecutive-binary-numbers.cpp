class Solution {
public:
    string Binary(int num){
        string s= "";
        while(num>0){
            s+= num%2;
            num = num/2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int concatenatedBinary(int n) {
        string s ="";
        for(int i=1;i<=n;i++){
            s += Binary(i);
        }
        int num=0;
        for(int i=0;i<s.size();i++){
            num = (num*2+ s[i])%1000000007;
        }
        return num;
    }
};