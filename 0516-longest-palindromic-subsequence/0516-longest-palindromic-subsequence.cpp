class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());
        int len = s.size();
        vector<vector<int>>dp(len+1,vector<int>(len+1,0));
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                if(s[i-1]==s1[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[len][len];
    }
};