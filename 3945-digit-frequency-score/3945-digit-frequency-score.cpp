class Solution {
public:
    int digitFrequencyScore(int n) {
        int score =0;
        unordered_map<int,int>freq;
        while(n>0){
            int num  = n%10;
            freq[num]++;
            n = n/10;
        }
        for(auto pair:freq){
            score+= pair.first * pair.second;
        }
        return score;
    }
};