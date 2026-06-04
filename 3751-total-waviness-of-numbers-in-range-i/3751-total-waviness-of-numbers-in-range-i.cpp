class Solution {
public:
    int CountWaviness(string s){
        int count =0;
        for(int i=1;i<s.size()-1;i++){
            if(s[i]>s[i-1] && s[i]>s[i+1]) count++;
            if(s[i]<s[i-1] && s[i]<s[i+1]) count++;
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int countwaviness = 0;
        for(int i=num1;i<=num2;i++){
            string s = to_string(i);
            if(s.size()<=2) continue;
            countwaviness += CountWaviness(s);
        }
        return countwaviness;
    }
};