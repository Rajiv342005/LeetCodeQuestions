class Solution {
public:
    string clearDigits(string s) {
       stack<char>st;
       int index=0;
       string sf="";
       while(index<s.size()){
        if(s[index]-'0'>=0&&s[index]-'0'<=9){
            if(!st.empty()){
                st.pop();
            }
            else{
                st.push(s[index]);
            }
        }
        else{
            st.push(s[index]);
        }
        index++;
       };
       while(!st.empty()){
        sf+=st.top();
        st.pop();
       }
       reverse(sf.begin(),sf.end());
       return sf; 
    }
};