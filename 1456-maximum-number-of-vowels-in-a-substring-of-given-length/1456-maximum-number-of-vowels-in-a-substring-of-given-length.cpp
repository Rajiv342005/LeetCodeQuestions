class Solution {
public:
    int maxVowels(string s, int k) {
        int MaxVowel = INT_MIN;
        unordered_set<char>vowel = {'a','e','i','o','u'};
        int CurrWindowVowel = 0;
        for(int i=0;i<k;i++){
            if(vowel.count(s[i])) CurrWindowVowel++;
        }
        MaxVowel = max(MaxVowel,CurrWindowVowel);
        for(int i=k;i<s.size();i++){
            if(vowel.count(s[i])) CurrWindowVowel++;
            if(vowel.count(s[i-k])) CurrWindowVowel--;
            MaxVowel = max(MaxVowel,CurrWindowVowel);
        }
        return MaxVowel;
    }
};