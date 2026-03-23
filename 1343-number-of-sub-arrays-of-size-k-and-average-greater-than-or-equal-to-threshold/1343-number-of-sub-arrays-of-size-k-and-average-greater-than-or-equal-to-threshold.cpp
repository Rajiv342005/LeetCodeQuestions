class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0;
        int countsubarray = 0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        if(sum/k>=threshold) countsubarray++;
        for(int i=1;i<=arr.size()-k;i++){
            sum-=arr[i-1];
            sum+=arr[k+i-1];
            if(sum/k>=threshold) countsubarray++;
        }
        return countsubarray;
    }
};