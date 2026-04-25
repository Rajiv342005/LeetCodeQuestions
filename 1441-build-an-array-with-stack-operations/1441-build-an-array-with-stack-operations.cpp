class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        stack<int>st;
        int pointer1 = 1;
        int pointer =0;
        while(pointer1<=n && pointer<target.size()){
            st.push(pointer1);
            ans.push_back("Push");
            if(pointer1!=target[pointer]){
                st.pop();
                ans.push_back("Pop");
            }
            else pointer++;
            pointer1++;
        }
        return ans;
    }
};