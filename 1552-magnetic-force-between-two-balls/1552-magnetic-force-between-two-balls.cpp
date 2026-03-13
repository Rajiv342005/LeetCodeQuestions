class Solution {
public:
    bool check(vector<int>& position, int m,int mid){
        int ball =1;
        int dist = position[0];
        for(int i=1;i<position.size();i++){
            if((position[i]-dist)>=mid){
                ball++;
                dist = position[i];
            }
        }
        return ball>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1;
        int high = position[position.size()-1]-position[0];
        int dist =0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(position,m,mid)){
                dist = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return dist;
    }
};