class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowel = {'a','e','i','o','u'};
        unordered_map<char,pair<int,int>>used;
        for(int i=(int)s.size()-1;i>=0;i--){
            if(vowel.count(s[i])){
                used[s[i]].first++;
                used[s[i]].second = i;
            }
            else continue;
        }
        vector<pair<char,pair<int,int>>>nums;
        for(auto &it:used){
            nums.push_back(it);
        }
        sort(nums.begin(),nums.end(),[](pair<char,pair<int,int>>a,pair<char,pair<int,int>>b){
            if(a.second.first==b.second.first) return a.second.second<b.second.second;
            return a.second.first>b.second.first;
        });
        string sv = "";
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].second.first;j++){
                sv+=nums[i].first;
            }
        }
        int index=0;
        for(int i=0;i<s.size();i++){
            if(used.count(s[i])){
                s[i] = sv[index++];
            }
        }
        return s;
    }
};