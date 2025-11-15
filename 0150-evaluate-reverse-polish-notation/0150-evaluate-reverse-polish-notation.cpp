class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int index=0;
        int first=0;
        int second =0;
        while(index<tokens.size()){
            if(tokens[index]=="*"){
                first  = st.top();
                st.pop();
                second = st.top();
                st.pop();
                st.push(first*second);
                index++;
            }
            else if(tokens[index]=="+"){
                first  = st.top();
                st.pop();
                second = st.top();
                st.pop();
                st.push(first+second);index++;
            }
            else if(tokens[index]=="-"){
                first  = st.top();
                st.pop();
                second = st.top();
                st.pop();
                st.push(second-first);index++;
            }
            else if(tokens[index]=="/"){
                first  = st.top();
                st.pop();
                second = st.top();
                st.pop();
                st.push(second/first);index++;
            }
            else{
                int num = stoi(tokens[index]);
                st.push(num);
                index++;
            }
        }
        return st.top();
    }
};