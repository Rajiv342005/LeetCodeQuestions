class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<pair<int,int>>maxheap;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                maxheap.push({grid[i][j],i});
            }
        }
        long long Maxsum=0;
        int count=0;
        while(count<k && !maxheap.empty()){
            pair<int,int> num = maxheap.top();
            if(limits[num.second]>0){
                Maxsum+=num.first;
                count++;
                limits[num.second]--;
            }
            maxheap.pop();
        }

        return Maxsum;     
    }
};