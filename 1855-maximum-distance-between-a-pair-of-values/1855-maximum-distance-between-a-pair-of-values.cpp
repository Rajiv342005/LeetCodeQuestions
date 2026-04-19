class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxdist = 0;
        for(int j=0;j<nums2.size();j++){
            int low =0;
            int high = min(j,(int)nums1.size()-1);
            while(low<=high){
                int mid = low+(high-low)/2;
                if(nums1[mid]<=nums2[j]){
                    high=mid-1;
                }
                else low = mid+1;
            }
            if(low<nums1.size() && nums2[j]>=nums1[low]){
                maxdist = max(maxdist,j-low); 
            }
        }
        return maxdist;
    }
};