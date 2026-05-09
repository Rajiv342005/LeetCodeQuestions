class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string>mp;
        for(int i=0;i<heights.size();i++){
            mp[heights[i]] = names[i];
        }
        int idx = heights.size()-1;
        for(auto it:mp){
            names[idx--] = it.second;
        }
        return names;
    }
};