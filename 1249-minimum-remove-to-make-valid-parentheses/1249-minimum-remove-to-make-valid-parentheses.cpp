class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<int>st;
        int index =0;
        for(auto ch: s){
            if(ch=='('){
                st.push(index);
            }
            else if(ch==')'){
                if(!st.empty()){
                    if(s[st.top()]=='('){
                        st.pop();
                    }
                    else st.push(index);
                }
                else st.push(index);
            }
            index++;
        }
        index = s.size()-1;
        for(int i=index;i>=0;i--){
            if(!st.empty() && st.top()==i){
                st.pop();
                continue;
            } 
            ans+=s[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};