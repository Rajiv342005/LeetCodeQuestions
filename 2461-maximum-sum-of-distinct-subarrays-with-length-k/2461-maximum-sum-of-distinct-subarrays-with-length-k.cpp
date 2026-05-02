class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>freq;
       long long maxsum =0;
       long long currsum = 0;
       int distinct =0;
       for(int i=0;i<k;i++){
        currsum+=nums[i];
        if(freq[nums[i]]==0){
            distinct++;
        }
        freq[nums[i]]++;
       }
       if(distinct==k) maxsum = max(maxsum,currsum);
       for(int i=k;i<nums.size();i++){
        freq[nums[i-k]]--;
        currsum-=nums[i-k];
        currsum+=nums[i];
        if(freq[nums[i-k]]==0){
            distinct--;
        }
        if(freq[nums[i]]==0){
            distinct++;
        }
        freq[nums[i]]++;
        if(distinct==k) maxsum = max(maxsum,currsum);
       }
       return maxsum; 
    }

};