class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
       unordered_map<int,int>m;
       int sum=0;
       for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
       };
       for(auto it=m.begin();it!=m.end();it++){
        if(it->second%k==0) sum+=(it->second)*(it->first);
       };
       return sum; 
    }
};