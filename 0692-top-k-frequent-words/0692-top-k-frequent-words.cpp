class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>used;
        for(auto s: words){
            used[s]++;
        }
        vector<pair<string,int>>nums(used.begin(),used.end());
        sort(nums.begin(),nums.end(),[](pair<string,int>&a,pair<string,int>&b){
            if(a.second==b.second){
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(nums[i].first);
        }
        return ans;
    }
};