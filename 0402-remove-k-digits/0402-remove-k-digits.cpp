class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(char ch: num){
            int element = ch-'0';
            if(!st.empty()){
                // check whether stack's top is larger than current element.
                if(st.top()>element){
                    while(!st.empty() && k>0 && (st.top()>element)){
                        st.pop();
                        k--;
                    }
                }
            }
            st.push(element);
        }
        stack<int>helper;
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }
        while(!helper.empty() && helper.top()==0){
            helper.pop();
        }
        string ans = "";
        while(!helper.empty()){
            ans += helper.top()+'0';
            helper.pop();
        }
        return ans==""?"0":ans;
    }
};