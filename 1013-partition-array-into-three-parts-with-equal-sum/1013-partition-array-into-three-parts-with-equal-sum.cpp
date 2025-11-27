class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        int count=0;
        int intervals=0;
        int allZero=true;
        for(int &val:arr){
            if(val!=0) allZero=false;
            sum+=val;
        }
        if(allZero) return true;
        if(sum%3!=0) return false;
        intervals = sum/3;
        sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==intervals){
                if(count==2) return true;
                count++;
                sum=0; 
            }
        }
        return count==3;
    }
};