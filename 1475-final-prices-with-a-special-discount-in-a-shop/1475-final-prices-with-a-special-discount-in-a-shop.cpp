class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>discount = prices;
        int index=0;
        stack<int>st;
        while(index<prices.size()){
            if(st.empty()){
                st.push(index);
            }
            else{
                if(prices[index]>prices[st.top()]){
                    st.push(index);
                }
                else{
                    while(!st.empty() && prices[st.top()]>=prices[index]){
                        discount[st.top()] = prices[st.top()]-prices[index];
                        st.pop();
                    }
                    st.push(index);
                }
            }
            index++;
        }
        return discount;
    }
};