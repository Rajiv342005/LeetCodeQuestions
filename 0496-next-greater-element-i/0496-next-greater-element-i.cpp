class Solution {
public:
    void NGE(vector<int>&nums2,vector<int>&ans){
        stack<int>st;
        int index=0;
        while(index<nums2.size()){
            if(st.empty()) st.push(index);
            else{
                if(nums2[index]<nums2[st.top()]){
                    st.push(index);
                }
                else{
                    while(!st.empty() && nums2[index]>nums2[st.top()]){
                        ans[st.top()] = nums2[index];
                        st.pop(); 
                    }
                    st.push(index);
                }
            }
            index++;
        }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nextGreater(nums2.size(),-1);
        vector<int>ans(nums1.size(),-1);
        NGE(nums2,nextGreater);
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans[i] = nextGreater[j];
                    break;
                }
                else continue;
            }
        }
        return ans;
    }
};