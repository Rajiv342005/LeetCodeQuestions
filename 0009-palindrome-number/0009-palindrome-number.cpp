class Solution {
public:
    bool isPalindrome(int x) {
        long long NewNumber=0;
        int rem;
        int num = x;
        while(num>0){
            rem = num%10;
            NewNumber = NewNumber*10 + rem;
            num = num/10;
        }
        if(x==NewNumber && x>=0){
            return true;
        }
        else{
            return false;
        }
        
    }
};