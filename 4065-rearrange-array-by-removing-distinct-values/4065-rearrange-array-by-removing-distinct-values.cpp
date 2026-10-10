class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>freq(101,0);
        for(int val: nums) freq[val]++;
        vector<int>ans(nums.size());
        int index = 0;
        int length = nums.size();
        while(length>0){
            for(int i=0;i<101;i++){
                if(freq[i]){
                    ans[index] = i; 
                    freq[i]--;
                    index++;
                    length--;
                }
            } 
        }
        return ans;
    }
};