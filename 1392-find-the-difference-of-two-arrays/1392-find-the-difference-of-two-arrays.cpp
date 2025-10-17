class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int index1=0;
        int index2=0;
        int previous =-1001;
        vector<int>v1;
        vector<int>v2;
        vector<vector<int>>result;
        while(index1<nums1.size() && index2<nums2.size()){
            if(nums1[index1]==nums2[index2]){
                index1++;
            }
            else if(nums1[index1]>nums2[index2]){
                index2++;
            }
            else{
                if(previous!=nums1[index1]){
                    v1.push_back(nums1[index1]);
                    previous = nums1[index1];
                    index1++;
                }
                else index1++;
            }
        }
        while(index1<nums1.size()){
            if(previous!=nums1[index1]){
                v1.push_back(nums1[index1]);
                previous = nums1[index1];
                index1++;
            }
            else index1++;
        }
        // Checking on the second Array....
        index1=0;
        index2=0;
        previous =-1001;
        while(index1<nums1.size() && index2<nums2.size()){
            if(nums1[index1]==nums2[index2]){
                index2++;
            }
            else if(nums1[index1]<nums2[index2]){
                index1++;
            }
            else{
                if(previous!=nums2[index2]){
                    v2.push_back(nums2[index2]);
                    previous = nums2[index2];
                    index2++;
                }
                else index2++;
            }
        }
        while(index2<nums2.size()){
            if(previous!=nums2[index2]){
                v2.push_back(nums2[index2]);
                previous = nums2[index2];
                index2++;
            }
            else index2++;
        }
        result.push_back(v1);
        result.push_back(v2);
        return result;
    }
};