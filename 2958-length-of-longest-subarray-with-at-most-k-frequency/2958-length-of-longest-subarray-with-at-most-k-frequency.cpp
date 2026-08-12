class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int val:nums){
            freq[val] = 0;
        }
        int start = 0;
        int pointer = 0;
        int len = 0;
        while(pointer<nums.size()){
            if(freq[nums[pointer]]==k){
                while(start<pointer && nums[start]!=nums[pointer]){
                    freq[nums[start]]--;
                    start++;
                }
                start++;
            }
            else{
                freq[nums[pointer]]++;
            }
            len = max(len,pointer-start+1);
            pointer++;
        }
        return len;
    }
};