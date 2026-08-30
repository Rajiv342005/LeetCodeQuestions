class Solution {
public:
    string transformation(int n,vector<int>converter){
        string ls = "";
        while(n>0){
            int idx = 25;
            while(converter[idx]>n){
                idx--;
            }
            ls += ('a'+idx);
            n -= converter[idx];
        }
        return ls;
    }
    vector<string> largestString(vector<int>& nums) {
        vector<int>converter(26,0);
        int base = 1;
        for(int i=0;i<26;i++){
            converter[i] = base;
            base *= 2;
        }
        int idx = 0;
        vector<string>ans(nums.size());
        for(int n:nums){
            ans[idx] = transformation(n,converter);
            idx++;
        }
        return ans;
    }
};