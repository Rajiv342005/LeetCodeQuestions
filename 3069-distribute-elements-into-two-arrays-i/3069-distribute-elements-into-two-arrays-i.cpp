class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        for(int element: nums){
            int n = arr1.size();
            int m = arr2.size();
            if(n==0){
                arr1.push_back(element);
            }
            else if(m==0){
                arr2.push_back(element);
            }
            else{
                if(arr1[n-1] >= arr2[m-1]){
                    arr1.push_back(element);
                }
                else{
                    arr2.push_back(element);
                }
            }
        }
        vector<int>resultArray;
        for(auto element:arr1){
            resultArray.push_back(element);
        }
        for(auto element:arr2){
            resultArray.push_back(element);
        }
        return resultArray;
    }
};