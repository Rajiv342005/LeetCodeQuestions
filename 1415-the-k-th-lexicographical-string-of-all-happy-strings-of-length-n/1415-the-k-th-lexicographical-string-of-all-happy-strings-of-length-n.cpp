class Solution {
public:
    string getHappyString(int n, int k) {
        int totalways = 3*pow(2,n-1);
        char prev ='#';
        if(k>totalways) return "";
        string ans = "";
        for(int i=0;i<n;i++){
            int block = pow(2,n-1-i);
            for(char ch:{'a','b','c'}){
                if(ch==prev) continue;
                if(k>block)
                k -=block;
                else{
                    ans+=ch;
                    prev = ch;
                    break;
                }
            }
        }
        return ans;   
    }
};