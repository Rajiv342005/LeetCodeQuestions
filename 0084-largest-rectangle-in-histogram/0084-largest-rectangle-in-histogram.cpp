class Solution {
public:
    void PushRight(vector<int>&nums,vector<int>&ans){
        stack<int>st;
        int index=0;
        while(index<nums.size()){
            if(st.empty()){
                st.push(index);
            }
            else{
                if(nums[index]>=nums[st.top()]){
                    st.push(index);
                }
                else{
                    while(!st.empty() && nums[index]<nums[st.top()]){
                        ans[st.top()] = index;
                        st.pop();
                    }
                    st.push(index);
                }
            }
            index++;
        }
        while(!st.empty()){
            ans[st.top()] = index;
            st.pop();
        }
    }
    void PushLeft(vector<int>&nums,vector<int>&ans){
        stack<int>st;
        int index=nums.size()-1;
        while(index>=0){
            if(st.empty()){
                st.push(index);
            }
            else{
                if(nums[index]>=nums[st.top()]){
                    st.push(index);
                }
                else{
                    while(!st.empty() && nums[index]<nums[st.top()]){
                        ans[st.top()] = index;
                        st.pop();
                    }
                    st.push(index);
                }
            }
            index--;
        }
        while(!st.empty()){
            ans[st.top()] = index;
            st.pop();
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>Leftflown(heights.size());
        vector<int>Rightflown(heights.size());
        PushRight(heights,Rightflown);
        PushLeft(heights,Leftflown);
        int MaxArea =INT_MIN;
        int CurrArea = 0;
        for(int i=0;i<heights.size();i++){
            CurrArea = heights[i]*(Rightflown[i]-Leftflown[i]-1);
            if(CurrArea>MaxArea) MaxArea = CurrArea;
            else continue;
        }
        return MaxArea;
    }
};