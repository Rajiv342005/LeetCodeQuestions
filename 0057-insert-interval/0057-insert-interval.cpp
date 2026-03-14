class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        for(auto interval:intervals){
            // No Overlapping(interval come before NewInterval)
            if(interval[1]<newInterval[0]){
                ans.push_back(interval);
            }
            // No Overlapping(newinterval come before Interval)
            else if(newInterval[1]<interval[0]){
                ans.push_back(newInterval);
                newInterval = interval;
            }
            // Overlapping Case
            else{
                newInterval[0] = min(newInterval[0],interval[0]);
                newInterval[1] = max(newInterval[1],interval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;    
    }
};