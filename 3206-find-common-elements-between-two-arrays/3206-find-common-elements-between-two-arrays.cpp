class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int count =0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int index1 =0;
        int index2 =0;
        while(index1<nums1.size() && index2<nums2.size()){
            if(nums1[index1]>nums2[index2]){
                index2++;
            }
            else if(nums1[index1]<nums2[index2]){
                index1++;
            }
            else{
                count++;
                index1++;
            }
        }
        ans.push_back(count);
        count=0;
        index1=0; index2=0;
        while(index1<nums1.size() && index2<nums2.size()){
            if(nums1[index1]>nums2[index2]){
                index2++;
            }
            else if(nums1[index1]<nums2[index2]){
                index1++;
            }
            else{
                count++;
                index2++;
            }
        }
        ans.push_back(count);
        return ans;
    }
    
};