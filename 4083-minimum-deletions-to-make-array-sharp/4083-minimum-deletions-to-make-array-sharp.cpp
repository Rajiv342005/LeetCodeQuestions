class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int minDel = 0;
        stack<int>st;
        for(int element:nums) st.push(element);
        while(st.size()>1){
            int first = st.top(); st.pop();
            int second = st.top(); st.pop();
            if((first^second) == 0) minDel++;
            st.push(second); 
        }
        return minDel;     
    }
};