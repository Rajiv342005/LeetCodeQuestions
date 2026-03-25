class Solution {
public:
    bool check(vector<int>& candies, int target, long long k){
        long long childcount = 0;    
        for(int i = 0; i < candies.size(); i++){
            childcount += candies[i] / target;
        }    
        return childcount >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        long long sum = 0;
        for(int i = 0; i < candies.size(); i++) sum += candies[i];
        long long high = sum / k;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(candies, mid, k)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};