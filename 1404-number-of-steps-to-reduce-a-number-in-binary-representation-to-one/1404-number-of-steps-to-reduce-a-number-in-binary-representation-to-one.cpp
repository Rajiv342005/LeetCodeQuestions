class Solution {
public:
    int numSteps(string s) {
        int count= 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') count++;
        }
        int step =0;
        while(count!=1 ||s[s.size()-1]!='1'){
            if(s[s.size()-1]=='1'){
               for(int i=s.size()-1;i>=0;i--){
                if(i==0 && s[i]=='1'){
                    s[i] ='0';
                    s.insert(0,1,'1');
                    break;
                }
                else if(s[i]=='0'){
                    s[i] = '1';
                    count++;
                    break;
                }
                else{
                    s[i] = '0';
                    count--;
                }
               }
            }
            else{
                s.pop_back();
                s.insert(0,1,'0');
            }
            step++;
        }
        return step;
    }
};