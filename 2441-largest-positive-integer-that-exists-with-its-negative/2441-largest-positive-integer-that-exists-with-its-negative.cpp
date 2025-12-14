class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>m;
        int larg = -1;
        int found;
        for(int i=0;i<nums.size();i++){
            found = -nums[i];
            if(m.count(found)){
                if(abs(found)>larg){
                    larg = abs(found);
                }
            }
            else{
                m[nums[i]]++;
            }
        }
        return larg;
    }
};