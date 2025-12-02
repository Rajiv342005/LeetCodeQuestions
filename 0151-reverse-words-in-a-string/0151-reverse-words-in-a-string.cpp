class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int index=0;
        string s1 = "";
        while(index<s.size()){
            if(s[index]!=' '){
                s1+=s[index];
            }
            else{
                if(s1!=""){
                    st.push(s1);
                }
                s1 = "";
            }
            index++;
        }
        if(s1!=""){
            st.push(s1);
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()){
                ans+=" ";
            }
        }
        return ans;
    }
};