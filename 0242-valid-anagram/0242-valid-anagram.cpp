class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<long long>nums(26,0);
       int index =0;
       int num=0;
       while(index<s.size()){
        num = s[index]-'a';
        nums[num]++;
        index++;
       }
       index=0;
       while(index<t.size()){
        num = t[index]-'a';
        if(nums[num]==0) return false;
        else nums[num]--;
        index++;
       }
       for(int i=0;i<26;i++){
        if(nums[i]!=0) return false;
       }
       return true;
    }
};