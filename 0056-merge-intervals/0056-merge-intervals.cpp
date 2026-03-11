class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        vector<int>prev = intervals[0];
        ans.push_back(prev);
        for(int i=1;i<intervals.size();i++){
            int first = intervals[i][0];
            int second = intervals[i][1];
            if(first>=prev[0] && first<=prev[1]){
                int max1 = max(first,second);
                max1 = max(max1,prev[0]);
                max1 = max(max1,prev[1]);
                int min1 = min(first,second);
                min1 = min(min1,prev[0]);
                min1 = min(min1,prev[1]);
                ans.pop_back();
                prev = {min1,max1};
                ans.push_back({min1,max1});
            }
            else{
                ans.push_back(intervals[i]);
                prev = intervals[i];
            }
        }
        return ans;
    }
};