class Solution {
public:
    void ReverseSubstr(stack<char>& st1) {
    string temp = "";
    while (!st1.empty() && st1.top()!='(') {
        temp += st1.top();
        st1.pop();
    }
    st1.pop();
    for (char ch : temp) {
        st1.push(ch);
    }
}
    string reverseParentheses(string s) {
        string ans= "";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                ReverseSubstr(st);
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};