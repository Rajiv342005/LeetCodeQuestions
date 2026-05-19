class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(),arr.end(),[x](int a ,int b){
            if(abs(x-a)==abs(x-b)) return a<b;
            return abs(x-a)<abs(x-b);
        });
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            ans[i] = arr[i];
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};