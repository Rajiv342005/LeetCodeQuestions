class Solution {
public:
    string addStrings(string num1, string num2) {
        int index1=num1.size()-1;
        int index2 = num2.size()-1;
        string s = "";
        int totalsum=0;
        int sum=0;
        int carry=0;
        while(index1>=0 && index2>=0){
            totalsum = (num1[index1]-'0')+(num2[index2]-'0')+carry;
            sum = totalsum%10;
            carry = totalsum/10;
            s+=(sum+'0');
            index1--,index2--;
        }
        while(index1>=0){
            totalsum = (num1[index1]-'0')+carry;
            sum = totalsum%10;
            carry = totalsum/10;
            s+=(sum+'0');
            index1--;
        }
        while(index2>=0){
            totalsum = (num2[index2]-'0')+carry;
            sum = totalsum%10;
            carry = totalsum/10;
            s+=(sum+'0');
            index2--;
        }
        if(carry!=0){
            s+=(carry+'0');
            carry=0;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};