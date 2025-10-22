class Solution {
public:
    string addBinary(string num1, string num2) {
       int index1=num1.size()-1;
       int index2 = num2.size()-1;
       char sum ='0';
       char carry = '0';
       int totalsum=0;
       string s = "";
       while(index1>=0 && index2>=0){
        totalsum = (num1[index1]-'0')+(num2[index2]-'0')+(carry-'0');
        if(totalsum==0){
            sum ='0';
            carry ='0';
        }
        else if(totalsum==1){
            sum = '1';
            carry='0';
        }
        else if(totalsum==2){
            sum ='0';
            carry = '1';
        }
        else if(totalsum==3){
            sum ='1';
            carry='1';
        }
        s+=sum;
        index1--,index2--;
       }
       while(index1>=0){
        totalsum = (num1[index1]-'0')+(carry-'0');
        if(totalsum==0){
            sum ='0';
            carry ='0';
        }
        else if(totalsum==1){
            sum = '1';
            carry='0';
        }
        else if(totalsum==2){
            sum ='0';
            carry = '1';
        }
        s+=sum;
        index1--;
       }
       while(index2>=0){
        totalsum = (num2[index2]-'0')+(carry-'0');
        if(totalsum==0){
            sum ='0';
            carry ='0';
        }
        else if(totalsum==1){
            sum = '1';
            carry='0';
        }
        else if(totalsum==2){
            sum ='0';
            carry = '1';
        }
        s+=sum;
        index2--;
       }
       if(carry!='0'){
        s+=carry;
        carry='0';
       }
       reverse(s.begin(),s.end());
       return s;
    }
};