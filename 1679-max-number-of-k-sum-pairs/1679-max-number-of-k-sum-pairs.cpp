class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int count=0;
        for(int i=0;i<nums.size();i++){
            int found = k-nums[i];
            if(freq[found]>=1){
                count++;
                freq[found]--;
            }
            else{
                freq[nums[i]]++;
            }
        }
        return count;
    }
};