class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maximum = prices[n-1];
        int maxprofit = 0;
        for(int i=n-1;i>=0;i--){
            maximum = max(maximum,prices[i]);
            if(prices[i]<maximum){
                maxprofit = max(maxprofit,maximum-prices[i]);
            }
        }
        return maxprofit;
    }
};