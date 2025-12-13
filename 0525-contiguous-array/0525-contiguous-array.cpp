class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int>m;
        int len=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) sum+=-1;
            else sum+=1;
            if(sum==0) len = i+1; 
            if(m.count(sum)){
                len = max(len,i-m[sum]);
            }
            else m[sum] = i;
        } 
        return len;  
    }
};