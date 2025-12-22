class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char &ch:s){
            freq[ch]++;
        }
        vector<pair<char,int>>nums(freq.begin(),freq.end());
        sort(nums.begin(),nums.end(),[](const pair<char,int>&a , const pair<char,int>&b){
            return a.second>b.second;
        });
        string ans ="";
        for(const pair<char,int>&p:nums){
            for(int i=0;i<p.second;i++){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};