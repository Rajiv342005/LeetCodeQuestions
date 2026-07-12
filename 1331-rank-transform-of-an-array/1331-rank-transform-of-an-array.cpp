class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      vector<pair<int,int>>nums(arr.size());
      for(int i=0;i<arr.size();i++){
        nums[i] = {arr[i],i};
      };
      sort(nums.begin(),nums.end());
      vector<int>ans(arr.size());
      int Rank = 0;
      int Previous = INT_MIN;
      for(auto pair:nums){
        int marks = pair.first;
        int index = pair.second;
        if(marks==Previous){
            ans[index] = Rank;
            Previous = marks;
        }
        else{
            Rank++;
            ans[index] = Rank;
            Previous = marks;
        }
      }
      return ans;
    }
};