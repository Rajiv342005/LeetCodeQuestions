class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>ans;
        int start = -1;
        int end = -1;
        unordered_set<int>used(nums.begin(),nums.end());
        for(int i=lower;i<=upper;i++){
            // If Element found
            if(used.count(i)){
                if(start!=-1){
                    ans.push_back({start,end});
                    start=end=-1;
                }
            }
            // If Element Not found
            else{
                if(start==-1){
                    start = i;
                    end = i;
                }
                else end = i;
            }
        }
        if(start!=-1) ans.push_back({start,end});
        return ans;
    }
};