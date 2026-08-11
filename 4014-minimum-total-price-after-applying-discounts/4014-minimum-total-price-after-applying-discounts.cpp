class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        priority_queue<int>price;
        priority_queue<int>discount;
        for(auto p:prices){
            price.push(p);
        }
        for(auto d:discounts){
            discount.push(d);
        }
        double totalminPrice = 0;
        int count = min(prices.size(),discounts.size());
        while(count>0){
            int p = price.top();
            price.pop();
            int d = discount.top();
            discount.pop();
            count--;
            totalminPrice += (p * (100 - d)) / 100.00;
        }
        while(!price.empty()){
            totalminPrice += price.top();
            price.pop();
        }
        return totalminPrice;
    }
};