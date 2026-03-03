class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());
        int len = s.size();
        vector<int>dp(len+1,0);
        int curr,prev;
        for(int i=1;i<=len;i++){
            curr=prev=0;
            for(int j=1;j<=len;j++){
                prev = curr;
                curr = dp[j];
                if(s[i-1]==s1[j-1]){
                    dp[j] = 1+prev;
                }
                else{
                    dp[j] = max(dp[j],dp[j-1]);
                }
            }
        }
        return dp[len];
    }
};