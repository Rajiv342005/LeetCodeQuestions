class Solution {
public:
    int calPoints(vector<string>&s) {
        int totalscore=0;
        stack<int>st;
        while(totalscore<s.size()){
            if(!st.empty() && s[totalscore]=="+"){
                int first = st.top(); st.pop();
                int second = st.top(); st.push(first);
                int sum = first+second;
                st.push(sum);
                totalscore++;
            }
            else if(!st.empty() && s[totalscore]=="C"){
                st.pop();
                totalscore++;
            }
            else if(!st.empty() && s[totalscore]=="D"){
                st.push(2*st.top());
                totalscore++;
            }
            else{
                st.push(stoi(s[totalscore]));
                totalscore++;
            }
        }
        totalscore =0;
        while(st.size()){
            totalscore+=st.top();
            st.pop();
        }
        return totalscore;  
    }
};