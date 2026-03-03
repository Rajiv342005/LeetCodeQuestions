class Solution {
public:
    int LPS(int len1, int len2, string &str1,string &str2,vector<vector<int>>&dp){
        if(len1==0 || len2==0) return 0;
        if(dp[len1][len2]!=-1) return dp[len1][len2];
        if(str1[len1-1]==str2[len2-1]) 
        return dp[len1][len2] = 1+LPS(len1-1,len2-1,str1,str2,dp);
        else
        return dp[len1][len2] = max(LPS(len1,len2-1,str1,str2,dp),LPS(len1-1,len2,str1,str2,dp));
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());
        int len = s.size();
        vector<vector<int>>dp(len+1,vector<int>(len+1,-1));
        return LPS(len,len,s,s1,dp);
    }
};