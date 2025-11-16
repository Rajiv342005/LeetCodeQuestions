class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>EI;
        vector<int>OI;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                EI.push_back(nums[i]);
            }
            else{
                OI.push_back(nums[i]);
            }
        }
        sort(EI.begin(),EI.end());
        sort(OI.begin(),OI.end());
        reverse(OI.begin(),OI.end());
        int index1=0;
        int index2=0;
        vector<int>ans;
        while(index1<EI.size() && index2<OI.size()){
            ans.push_back(EI[index1++]);
            ans.push_back(OI[index2++]);
        }
        while(index1<EI.size()){
            ans.push_back(EI[index1++]);
        }
        while(index2<OI.size()){
            ans.push_back(OI[index2++]);
        }
        return ans;
    }
};