class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>freqTable;
        for(int i=0;i<nums.size();i++){
            freqTable[nums[i]].push_back(i);
        }
        int specialCount = 0;
        vector<int>arr;
        for(auto &element:freqTable){
            arr = element.second;
            if(arr.size()!=3) continue;
            if((arr[1]-arr[0])==(arr[2]-arr[1])) specialCount++;
        }
        return specialCount;
    }
};