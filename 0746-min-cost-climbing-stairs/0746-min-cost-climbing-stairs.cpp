class Solution {
public:
    int minCostClimbingStairs(vector<int>& costs) { 
        int firstpos =0;
        int secondpos =0;
        for(int i=2;i<=costs.size();i++){
            int temp = secondpos;
            secondpos = min(firstpos+costs[i-2],secondpos+costs[i-1]);
            firstpos = temp;
        }
        return secondpos;     
    }
};