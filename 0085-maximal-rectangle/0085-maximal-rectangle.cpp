class Solution {
public:
    void pushright(vector<int>&sum,vector<int>&ans){
        stack<int>st;
        int index=0;
        while(index<sum.size()){
            if(st.empty()){
                st.push(index);
            }
            else{
                if(sum[index]>=sum[st.top()]){
                    st.push(index);
                }
                else{
                    while(!st.empty() && sum[index]<sum[st.top()]){
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
    void pushleft(vector<int>&sum,vector<int>&ans){
        stack<int>st;
        int index=sum.size()-1;
        while(index>=0){
            if(st.empty()){
                st.push(index);
            }
            else{
                if(sum[index]>=sum[st.top()]){
                    st.push(index);
                }
                else{
                    while(!st.empty() && sum[index]<sum[st.top()]){
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
    void Check(vector<int>&sum,vector<char>&nums,int &MaxArea){
        for(int i=0;i<nums.size();i++){
            if(nums[i]=='1') sum[i]++;
            else sum[i]=0;
        }
        vector<int>leftflown(nums.size());
        vector<int>rightflown(nums.size());
        pushright(sum,rightflown);
        pushleft(sum,leftflown);
        int currArea=0;
        for(int i=0;i<nums.size();i++){
            currArea = sum[i]*(rightflown[i]-leftflown[i]-1);
            if(currArea>MaxArea) MaxArea = currArea;
            else continue;
        }

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>sum(matrix[0].size(),0);
        int MaxArea=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            Check(sum,matrix[i],MaxArea);
        }
        return MaxArea;
    }
};