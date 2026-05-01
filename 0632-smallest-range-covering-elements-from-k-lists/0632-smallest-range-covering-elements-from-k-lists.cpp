class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minheap;
        int currMax = INT_MIN;
        int start = 0;
        int end = INT_MAX;
        for(int i=0;i<nums.size();i++){
            minheap.push({nums[i][0],{i,0}});
            currMax = max(currMax,nums[i][0]);
        }
        while(true){
            auto it = minheap.top();
            minheap.pop();
            int minValue = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(currMax-minValue < end-start){
                start = minValue;
                end = currMax;
            }
            if(col+1<nums[row].size()){
                minheap.push({nums[row][col+1],{row,col+1}});
                currMax = max(currMax,nums[row][col+1]);
            }
            else break;
        }
        return {start,end};
    }
};