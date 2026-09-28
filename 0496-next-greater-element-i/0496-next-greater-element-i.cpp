class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>NGE(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!st.empty()){
                // if stack top element is smaller than currrent element;
                if(nums2[st.top()]<nums2[i]){
                    while(!st.empty() && (nums2[st.top()]<nums2[i])){
                        NGE[st.top()] = nums2[i];
                        st.pop();
                    }
                }
            }
            st.push(i);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[nums2[i]] = NGE[i];
        n = nums1.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;    
    }
};