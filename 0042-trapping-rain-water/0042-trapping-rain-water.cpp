class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        stack<int>st;
        for(int i=0;i<height.size();i++){
            while(!st.empty() && height[st.top()]<height[i]){
                int valley = st.top();
                st.pop();
                if(st.empty()) break;
                int leftboundary = st.top();
                int width = i-leftboundary-1;
                int tall = min(height[i],height[leftboundary])-height[valley];
                water+=tall*width;
            }
            st.push(i);
        }
        return water;
    }
};