class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>temp;
        for(int i=1;i<=rowIndex+1;i++){
            vector<int>nums(i,1);
            if(i>2){
                for(int j=1;j<i-1;j++){
                    nums[j] = temp[j-1]+temp[j];
                }
            }
            temp = nums;
        }
        return temp;
    }
};