class Solution {
public:
    int minimumPushes(string word) {
        vector<int>minpush(8,0);
        int counter = 0;
        int CountPush = 0;
        for(char ch: word){
            CountPush += (minpush[counter]+1);
            // Insert One Word to the button;
            minpush[counter]++;
            counter = (counter+1)%8;
        }
        return CountPush;    
    }
};