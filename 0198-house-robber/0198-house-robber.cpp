class Solution {
public:
    int rob(vector<int>& nums) {
        // Space Optimization Approach..
        int prevHouse = 0;
        int prev2House = 0;
        for(int i=nums.size()-1;i>=0;i--){
            prev2House = max(prev2House+nums[i],prevHouse);
            int temp = prev2House;
            prev2House = prevHouse;
            prevHouse = temp;    
        }
        return prevHouse;
    }
};