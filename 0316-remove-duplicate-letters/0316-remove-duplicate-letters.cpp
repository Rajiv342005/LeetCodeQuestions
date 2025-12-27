class Solution {
public:
    string removeDuplicateLetters(string s) {
       unordered_map<char,int>freq;
       vector<bool>visited(26,false);
       stack<char>st;
       for(char ch:s){
        freq[ch]++;
       }
       int index=0;
       while(index<s.size()){
        freq[s[index]]--;
        if(st.empty()){
            st.push(s[index]);
            visited[s[index]-'a'] = true;
        }
        else if(visited[s[index]-'a']) {
            index++;
            continue;
        }
        else{
            if(st.top()<s[index]){
                st.push(s[index]);
                visited[s[index]-'a'] = true;
            }
            else{
                while(!st.empty()&&st.top()>s[index]&&freq[st.top()]){
                    visited[st.top()-'a'] = false;
                    st.pop();
                }
                st.push(s[index]);
                visited[s[index]-'a'] = true;
            }
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