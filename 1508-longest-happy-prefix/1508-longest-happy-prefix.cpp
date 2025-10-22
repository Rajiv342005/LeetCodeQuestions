class Solution {
public:
    string longestPrefix(string s) {
        vector<char> str(s.size()+1);
        vector<int> LPS(s.size()+1);
        for(int i=0;i<s.size();i++){
            str[i+1] = s[i];
            LPS[i] = 0;
        }
        LPS[s.size()] = 0;
        int first =0;
        int second=2;
        while(second<=s.size()){
            if(str[first+1]==str[second]){
                LPS[second] = first+1;
                first++,second++;
            }
            else{
                if(first==0) second++;
                else{
                    first = LPS[first];
                }
            }
        }
        int n = LPS[s.size()];
        string s3 = "";
        for(int i=1;i<=n;i++){
            s3+=str[i];
        }
        return s3;
    }
};