class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,pair<int,int>>used;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]%2==0){
                if(used.count(nums[i])){
                    used[nums[i]].first = i;
                    used[nums[i]].second++;
                }
                else{
                    used.insert({nums[i],{i,1}});
                }
            }
        }
        int fue =-1;
        for(auto &it: used){
            int ele = it.first;
            int idx = it.second.first;
            int count = it.second.second;
            if(count==1){
                if(fue==-1) fue = idx;
                else if(fue>idx)
                fue = idx;
            }
        }
        if(fue==-1) return-1;
        return nums[fue];
    }
};