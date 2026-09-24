class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maximumScore = 0;
        int windowSum = 0;
        vector<int>prefixSum(n+1);
        vector<int>suffixSum(n+1);
        prefixSum[0] = 0;
        for(int i=1;i<=n;i++){
            prefixSum[i] = prefixSum[i-1]+cardPoints[i-1];
        }
        suffixSum[n] = 0;
        for(int i=n-1;i>=0;i--){
            suffixSum[i] = suffixSum[i+1]+cardPoints[i];
        }
        for(int i=0;i<=k;i++){
            windowSum = prefixSum[i]+suffixSum[n-(k-i)];
            maximumScore = max(maximumScore,windowSum);
        }
        return maximumScore;
    }
};