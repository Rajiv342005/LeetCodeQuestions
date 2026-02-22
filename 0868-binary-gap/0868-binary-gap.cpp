class Solution {
public:
    int binaryGap(int n) {
        string s = "";
        while(n>0){
            s+= n%2;
            n = n/2;
        }
        int first = -1;
        int gap =0;
        for(int i=0;i<s.size();i++){
            if(s[i]==1){
                first = i;
                break;
            }
        }
        if(first==-1) return 0;
        for(int i=first+1;i<s.size();i++){
            if(s[i]==1){
                gap = max(gap,i-first);
                first = i;
            }
        }
        return gap;
    }
};