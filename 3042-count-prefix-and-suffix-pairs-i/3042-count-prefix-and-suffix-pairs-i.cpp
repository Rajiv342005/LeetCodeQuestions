class Solution {
public:
    bool CheckPrefixSuffix(string str1,string str2){
        bool prefix = true;
        bool suffix = true;
        int index1 = 0;
        int index2 = 0;
        if(str1.size() > str2.size()) prefix = false;
        // Prefix Checker.
        while(index1<str1.size() && index2<str2.size() && prefix){
            if(str1[index1]==str2[index2]){
                index1++;
                index2++;
            }
            else{
                prefix = false;
                break;
            }

        }
        // Suffix Checker..
        index1 = str1.size()-1;
        index2 = str2.size()-1;
        if(str1.size() > str2.size()) suffix = false;

        while(index1>=0 && index2>=0 && suffix){
            if(str1[index1]==str2[index2]){
                index1--;
                index2--;
            }
            else{
                prefix = false;
                break;
            }

        }
        return prefix && suffix;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(CheckPrefixSuffix(words[i],words[j])) count++;
            }
        }
        return count;
    }
};