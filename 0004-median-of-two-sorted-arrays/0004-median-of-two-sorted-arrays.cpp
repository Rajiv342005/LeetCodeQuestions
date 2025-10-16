class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>mergeArray;
        int pointer1 = 0;
        int pointer2 = 0;
        while(pointer1<nums1.size() && pointer2<nums2.size()){
            if(nums1[pointer1]>nums2[pointer2]){
                mergeArray.push_back(nums2[pointer2]);
                pointer2++;
            }
            else{
                mergeArray.push_back(nums1[pointer1]);
                pointer1++;
            }
        }
        while(pointer1<nums1.size()){
            mergeArray.push_back(nums1[pointer1]);
            pointer1++;
        }
        while(pointer2<nums2.size()){
            mergeArray.push_back(nums2[pointer2]);
            pointer2++;
        }
        int n = mergeArray.size();
        if(n%2==0){
            double mean = (mergeArray[n/2]+mergeArray[n/2-1])/2.00;
            return mean ;
        }
        else{
            return mergeArray[n/2];
        }

    }
};