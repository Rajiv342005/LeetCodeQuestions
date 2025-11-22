class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        int pointer2=1;
        while(pointer2<s.size()){
            sum+= abs((s[pointer2-1]-'a')-(s[pointer2++]-'a'));
        }
        return sum;
    }
};