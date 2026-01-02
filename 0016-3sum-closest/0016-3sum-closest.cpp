class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 0;
        int mindiff = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int right = nums.size()-1;
            int left = i+1;
            while(left<right){
                int sum = nums[i]+nums[right]+nums[left];
                if(abs(sum-target)<mindiff){
                    mindiff = abs(sum-target);
                    closest = sum;
                }
                if(sum==target) return sum;
                else if(sum<target){
                    left++;
                }
                else right--;
            }
        }
        return closest;
    }
};