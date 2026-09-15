class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>freqTable;
        for(int i=0;i<nums.size();i++){
            freqTable[nums[i]].push_back(i);
        }
        int specialCount = 0;
        vector<int>arr;
        unordered_set<int>count;
        for(auto & element: freqTable){
            arr = element.second;
            count.clear();
            if(arr.size()<3) continue;
            for(int i=1;i<arr.size();i++){
                count.insert(arr[i]-arr[i-1]);
            }
            if(count.size()==1) specialCount++;
        }
        return specialCount;
    }
};