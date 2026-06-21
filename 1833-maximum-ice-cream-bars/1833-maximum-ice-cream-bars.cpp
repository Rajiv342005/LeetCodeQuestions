class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int totalIcecream = 0;
        for(auto cost:costs){
            if(cost<=coins){
                totalIcecream++;
                coins-=cost;
            }
            else return totalIcecream;
        }
        return totalIcecream;
    }
};