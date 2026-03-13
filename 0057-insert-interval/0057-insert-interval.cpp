class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<int>prev = intervals[0];
        ans.push_back(prev);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=prev[0] && intervals[i][0]<=prev[1]){
                int max1 = max(prev[1],intervals[i][1]);
                ans.pop_back();
                prev = {prev[0],max1};
                ans.push_back({prev[0],max1});
            }
            else{
                ans.push_back(intervals[i]);
                prev = intervals[i];
            }
        }
        return ans;
       
    }
};