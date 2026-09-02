class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        unordered_set<int>used;
        int oddcount=0;
        int evencount=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                evencount++;
            }
            else{
                oddcount++;
            }
            used.insert(nums1[i]);
        }
        if(nums1.size()==oddcount || nums1.size()==evencount) return 1;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums1.size();j++){
                int diff = nums1[i]-nums1[j];
                if(used.count(diff) && i!=j){
                    continue;
                }
                else{
                    used.insert(diff);
                    if(diff%2==0){
                        evencount++;
                    }
                    else oddcount++;
                }
            }
        }
        return nums1.size()<=evencount || nums1.size()<=oddcount;
    }
};