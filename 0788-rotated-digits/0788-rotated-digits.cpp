class Solution {
public:
    int rotatedDigits(int n) {
        int counter =0;
        unordered_set<int>used = {3,4,7};
        unordered_set<int>goodnumber = {2,5,6,9};
        for(int i=0;i<=n;i++){
            string s = to_string(i);
            bool valid = true;
            bool isgood = false;
            for(int j=0;j<s.size();j++){
                if(used.count(s[j]-'0')){
                    valid = false;
                    break;
                }
                if(goodnumber.count(s[j]-'0')){
                    isgood = true;
                }
            }
            if(valid && isgood){
                counter++;
            }  
        }
        return counter;
    }
};