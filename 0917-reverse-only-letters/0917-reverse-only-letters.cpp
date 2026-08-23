class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> st;
        // Inserting into Stack.
        for(char ch:s){
            if(isalpha(ch)) st.push(ch);
        }
        // Reverse the Character.
        for(char &ch:s){
            if(isalpha(ch)){
                ch = st.top();
                st.pop();
            }
        }
        return s;
    }
};