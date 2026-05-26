class Solution {
public:
    bool IsValid(string Parenthesis){
        stack<char>st;
        for(auto ch:Parenthesis){
            if(ch=='(') st.push(ch);
            else{
                if(st.empty()) return false;
                else if(st.top()!='(') return false;
                else st.pop();   
            }
        }
        return st.empty();
    }
    void GenerateParenthesis(string parenthesis,vector<string>&ans,int n){
        if(parenthesis.size()==2*n){
            if(IsValid(parenthesis))
            ans.push_back(parenthesis);
            return;
        }

        GenerateParenthesis(parenthesis+"(",ans,n);
        GenerateParenthesis(parenthesis+")",ans,n);

        return;
    }
    vector<string> generateParenthesis(int n) {
        string parenthesis = "(";
        vector<string>ans;
        GenerateParenthesis(parenthesis,ans,n);
        return ans;
    }
};