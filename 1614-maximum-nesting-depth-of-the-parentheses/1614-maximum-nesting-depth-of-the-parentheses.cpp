class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int index=0;
        int Nested=0;
        int Max=0;
        while(index<s.size()){
            if(s[index]=='('){
                st.push(s[index]);
                Nested++;
            }
            else if(s[index]==')'&&!st.empty() && st.top()=='(')
            {
                if(Nested>Max) Max=Nested;
                Nested--;
            }
            index++;
        }
        return Max;
    }
};