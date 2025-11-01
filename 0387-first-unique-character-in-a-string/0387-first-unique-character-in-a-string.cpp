class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>nums(26,0);
        for(int i=0;i<s.size();i++){
            nums[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(nums[s[i]-'a']==1) return i;
            else continue;
        }
        return -1; 
    }
};