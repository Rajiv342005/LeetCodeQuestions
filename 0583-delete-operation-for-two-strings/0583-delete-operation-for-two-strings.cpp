class Solution {
public:
    int minDistance(string word1, string word2) {
        // Space Optimization; 
        int m = word1.size();
        int n = word2.size();
        vector<int>dp(n+1,0);
        int temp,prev;
        for(int i=m-1;i>=0;i--){
            prev = dp[n];
            for(int j=n-1;j>=0;j--){
                temp = dp[j];
                if(word1[i]==word2[j]){
                    dp[j] = 1+prev;
                }
                else{
                    dp[j] = max(dp[j],dp[j+1]);
                }
                prev = temp;
            }
        }
        int lcs = dp[0];
        return m+n - 2*lcs;
    }
};