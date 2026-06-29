class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int counter = 0;
        for(string pattern:patterns){
            if(word.find(pattern)!=string::npos) counter++;
        }
        return counter;
    }
};