class Solution {
public:
    int minimumPushes(string word) {
        int minpush = 0;
        int counter = 0;
        vector<int>button(8,0);
        unordered_map<char,int>freq;

        for(char ch:word){
            freq[ch]++;
        }
        vector<pair<char,int>>nums(freq.begin(),freq.end());
        sort(nums.begin(),nums.end(),[](pair<char,int>a,pair<char,int>b){
            return a.second > b.second;
        });
        for(auto item: nums){
            char ch = item.first;
            int freq = item.second;
            button[counter] += 1;
            minpush += (button[counter])*freq;
            counter = (counter+1)%8;
        }
        return minpush;
    }
};