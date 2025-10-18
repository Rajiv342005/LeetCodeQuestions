class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int index1=0;
        stack <char> s1;
        stack <char> s2;
        while(index1<s.size()){
            if(s[index1]=='#'){
                if(!s1.empty()) s1.pop();
                index1++;
            }
            else{
                s1.push(s[index1]);
                index1++;
            }
        }
        index1 =0;
        while(index1<t.size()){
            if(t[index1]=='#'){
                if(!s2.empty()) s2.pop();
                index1++;
            }
            else{
                s2.push(t[index1]);
                index1++;
            }
        }

        if(s1.size()!=s2.size()) return false;
        while(!s1.empty()){
            if(s1.top()!=s2.top()) return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};