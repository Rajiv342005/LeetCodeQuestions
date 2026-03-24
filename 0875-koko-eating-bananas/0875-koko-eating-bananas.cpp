class Solution {
public:
    bool check(vector<int>&piles,int mid,int h){
        int counter =0;
        for(int i=0;i<piles.size();i++){
            counter+=(piles[i] + mid - 1) / mid;
        }
        return counter<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high = 0;
        for(int i=0;i<piles.size();i++){
            high = max(piles[i],high);
        }
        while(low<high){
            int mid = low+ (high-low)/2;
            if(check(piles,mid,h)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};