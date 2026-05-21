class Solution {
public:
    int LCS(int index1 ,int index2,string &text1,string &text2,vector<vector<int>>&dp){
        if(index1>=text1.size()||index2>=text2.size()) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        // Checking the Character of str is matched or Not.
        if(text1[index1]==text2[index2]){
            return dp[index1][index2] = 1+LCS(index1+1,index2+1,text1,text2,dp);
        }
        int len1 = LCS(index1+1,index2,text1,text2,dp);
        int len2 = LCS(index1,index2+1,text1,text2,dp);
        return dp[index1][index2] = max(len1,len2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return LCS(0,0,text1,text2,dp);
    }
};