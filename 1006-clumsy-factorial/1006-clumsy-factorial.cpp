class Solution {
public:
    int clumsy(int n) {
        stack<int>st;
        int ops = 0;
        st.push(n);
        n--;
        while(n>0){
            int first = st.top();
            st.pop();
            if(ops==0) st.push(first*n);
            else if(ops==1) st.push(first/n);
            else{
                st.push(first);
                st.push(n);
            }
            ops = (ops+1)%4;
            n--;
        }
        stack<int>nst;
        while(!st.empty()){
            nst.push(st.top());
            st.pop();
        }
        ops = 0;
        while(nst.size()>1){
            int first = nst.top(); nst.pop();
            int second = nst.top(); nst.pop();
            if(ops==0) nst.push(first+second);
            else  nst.push(first-second);
            ops = (ops+1)%2;
        }
        return nst.top();    
    }
};