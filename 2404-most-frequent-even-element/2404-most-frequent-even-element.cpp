class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                m[nums[i]]++;
            }
            else continue;
        }
        vector<pair<int,int>>v(m.begin(),m.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
        if (a.second == b.second)
        return a.first < b.first;   
        return a.second > b.second;
        });
        if(v.size()==0) return -1;
        return v[0].first;     
    }
};