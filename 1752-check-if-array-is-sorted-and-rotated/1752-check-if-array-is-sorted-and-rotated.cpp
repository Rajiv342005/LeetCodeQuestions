class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool SRA = true; // Sorted Rotated Array
        for(int i=0;i<n;i++){
            SRA = true;
            for(int j=i+1;j<n+i;j++){
                if(nums[(j-1)%n]>nums[(j)%n]){
                    SRA = false;
                    break;
                }
                
            }
            if(SRA) return true;
        }
        return false;
    }
};