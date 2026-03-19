class Solution {
public:
    bool check(vector<int>&wt,int mid,int &days){
        int day =1;
        int sum =0;
        for(int i=0;i<wt.size();i++){
            sum+=wt[i];
            if(sum>mid){
                day++;
                sum = wt[i];
            }
        }
        return days>=day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low =weights[0];
        int high =0;
        for(int i=0;i<weights.size();i++){
            low = max(low,weights[i]);
            high+=weights[i];
        }
        if(days==1) return high;
        int minwt =0;
        while(low<high){
            int mid = low+(high-low)/2;
            if(check(weights,mid,days)){
                minwt = mid;
                high = mid;
            }
            else low = mid+1;
        }
        return minwt;
    }
};