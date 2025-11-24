class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0; int count=0;
        for(int &val:nums){
            if(val%3==0 && val%2==0){
                sum+=val; count++;
            }
            else continue;
        }
        if(count) return sum/count;
        else return 0;
    }
};