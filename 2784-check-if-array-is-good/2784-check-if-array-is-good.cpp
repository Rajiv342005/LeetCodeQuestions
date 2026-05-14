class Solution {
public:
    bool isGood(vector<int>& nums) {
      int maximum= INT_MIN;
      unordered_map<int,int>freq;
      for(auto val:nums){
        maximum = max(maximum,val);
        freq[val]++;
      };
      for(int i=1;i<maximum;i++){
        if(freq.count(i) && freq[i]==1) continue;
        else return false;
      };
      if(freq[maximum]==2) return true;
      return false; 
    }
};