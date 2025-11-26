class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>ans(arr.size(),-1);
        int max=INT_MIN;
        for(int i=0;i<arr.size()-1;i++){
            max=INT_MIN;
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]>max) max=arr[j];
            }
            ans[i] = max;
        }
        return ans;
    }
};