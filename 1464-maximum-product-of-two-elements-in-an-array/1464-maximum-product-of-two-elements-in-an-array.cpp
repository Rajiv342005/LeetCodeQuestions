class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>p;
        for(int i=0;i<nums.size();i++){
            p.push(nums[i]-1);
        }
        int num1 = p.top(); p.pop();
        int num2 = p.top();
        return num1*num2;
    }
};