class Solution {
public:
    int clumsy(int n) {
        int index=0;
        int i=0;
        int num =0;
        stack<int> st;
        st.push(n); n--;
        while(n)
        {
            if(i==0)
            {
              num = st.top();
              st.pop();
              st.push(num*n);  
            }
            else if(i==1)
            {
                num = st.top();
                st.pop();
                st.push(num/n);
            }
            else
            {
                st.push(n);
            }
            i = (i+1)%4;
            n--;
        }
        stack <int> ans;
        while(st.size()){
            ans.push(st.top());
            st.pop();
        }
        bool temp=true;
        int sum = ans.top();
        ans.pop();
        while(ans.size()){
            if(temp){
                sum+= ans.top();
                ans.pop();
            }
            else{
                sum-= ans.top();
                ans.pop();
            }
            temp = !temp;
        }
        return sum;
    }
};