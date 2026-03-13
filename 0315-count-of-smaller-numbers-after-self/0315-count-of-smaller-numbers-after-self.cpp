class Solution {
public:
    void Merge(vector<pair<int,int>>&nums,int low,int mid,int high,vector<int>&count){
        int n1 = mid-low+1;
        int n2 = high-mid;
        vector<pair<int,int>>L(n1);
        vector<pair<int,int>>R(n2);
        for(int i=0;i<n1;i++){
            L[i] = nums[low+i];
        }
        for(int i=0;i<n2;i++){
            R[i] = nums[mid+1+i];
        }
        int i=0,j=0;
        int k=low;
        int rightCount = 0;
        while(i<n1 && j<n2){
            if(L[i].first<=R[j].first){
                count[L[i].second] += rightCount;
                nums[k++] = L[i++];
            }
            else{
                rightCount++;
                nums[k++] = R[j++];
            }
        }
        while(i<n1){
            count[L[i].second] += rightCount;
           nums[k++] = L[i++]; 
        }
        while(j<n2){
            nums[k++] = R[j++];
        }
        return;
    }
    void MergeSort(vector<pair<int,int>>&nums,int low,int high,vector<int> &count){
        if(low>=high) return;
        int mid = low+(high-low)/2;
        MergeSort(nums,low,mid,count);
        MergeSort(nums,mid+1,high,count);
        Merge(nums,low,mid,high,count);
        return;
    }
    vector<int> countSmaller(vector<int>& nums1) {
        vector<pair<int,int>>nums(nums1.size());
        for(int i=0;i<nums1.size();i++){
            nums[i]={nums1[i],i};
        }
        vector<int>count(nums.size(),0);
        int low =0;
        int high = nums.size()-1;
        MergeSort(nums,low,high,count);
        return count;
    }
};