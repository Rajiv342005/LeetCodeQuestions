class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool>ans(n);
        int mindiff;
        for(int i=0;i<n;i++){
            mindiff = INT_MIN;
            for(int j=0;j<n;j++){
                int diff = (candies[j]-candies[i]);
                mindiff = max(mindiff,diff); 
            } 
            ans[i] = mindiff<=extraCandies;  
        }
        return ans;
    }
};