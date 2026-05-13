class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int>freq;
        // Storing the freq of Each Element.
        for(auto ch:s){
            freq[ch]++;
        }
        int ans =0;
        // Check one by one char and their mirror character freq;
        for(char ch:s){
            if(freq.count(ch)){
                // Check the element ch is whether digit or character.
                if(isdigit(ch)){
                    ans+= abs(freq[ch]-freq[('9'-ch)+'0']);
                    freq.erase(ch);
                    freq.erase(('9'-ch)+'0');
                }
                else{
                    ans+= abs(freq[ch]-freq[('z'-ch)+'a']);
                    freq.erase(ch);
                    freq.erase(('z'-ch)+'a');
                }
            }
        }
        return ans;
    }
};