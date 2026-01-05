class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        int index=0;
        while(index<s.size()){
           if(!st.empty() && s[index]=='*'){
            st.pop();
           }
           else{
            st.push(s[index]);
           }
           index++;
        }
        string sf = "";
        while(!st.empty()){
            sf+=st.top();
            st.pop();
        }
        reverse(sf.begin(),sf.end());
        return sf;
    }
};