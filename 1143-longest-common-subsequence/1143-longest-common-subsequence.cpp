class Solution {
public:
    int LCS(int len1,int len2,string &str1,string &str2,vector<vector<int>>&dp){
        if(len1==0 || len2==0) return 0;
        if(dp[len1][len2]!=-1) return dp[len1][len2];
        // If character were Matched..
        if(str1[len1-1]==str2[len2-1]){
            return dp[len1][len2]=1+LCS(len1-1,len2-1,str1,str2,dp);
        }
        // If character does't match..
        else{
            return dp[len1][len2]=max(LCS(len1,len2-1,str1,str2,dp),LCS(len1-1,len2,str1,str2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,-1));
        return LCS(len1,len2,text1,text2,dp);
    }
};