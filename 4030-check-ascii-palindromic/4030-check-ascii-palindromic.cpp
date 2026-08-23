class Solution {
public:
    string getBinary(int num){
        if(num==0) return "";
        string ans = getBinary(num/2);
        ans.push_back(num%2+'0');
        return ans;
    }
    bool isPalindromic(string s) {
        string binaryString = "";
        for(auto ch:s){
            int ascii = ch;
            string binary = getBinary(ascii);
            for(int i=0;i<8-binary.size();i++){
                binaryString.push_back('0');
            }
            binaryString += binary;
        }
        int start = 0;
        int end = binaryString.size()-1;
        while(start<end){
            if(binaryString[start]==binaryString[end]){
                start++;
                end--;
            }
            else return false;
        }
        return true;
    }
};