class Solution {
public:
    char findTheDifference(string s, string t) {
        int index1 =0;
        int index2=0;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        while(index1<s.size() && index2<t.size() &&s[index1]==t[index2]){
            index1++;
            index2++;
        }
        return t[index2];
    }
};