class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        unordered_set<int>rep;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        for(auto &it:freq){
            if(rep.count(it.second)) return false;
            else rep.insert(it.second);
        }
        return true;
    }
};