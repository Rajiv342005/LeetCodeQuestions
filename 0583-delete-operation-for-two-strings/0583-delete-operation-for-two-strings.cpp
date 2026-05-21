class Solution {
public:
    int LCS(int pointer1,int pointer2,string &word1,string &word2,vector<vector<int>>&dp){
        if(pointer1>=word1.size() || pointer2>=word2.size()) return 0;

        if(dp[pointer1][pointer2]!=-1) return dp[pointer1][pointer2];

        if(word1[pointer1]==word2[pointer2]){
            return dp[pointer1][pointer2] =  1+LCS(pointer1+1,pointer2+1,word1,word2,dp);
        }

        int len1 = LCS(pointer1+1,pointer2,word1,word2,dp);
        int len2 = LCS(pointer1,pointer2+1,word1,word2,dp);
        return dp[pointer1][pointer2] = max(len1,len2);
    }
    int minDistance(string word1, string word2) {
        // Traditional Recursion 
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int lcs = LCS(0,0,word1,word2,dp);
        return m+n - 2*lcs;
    }
};