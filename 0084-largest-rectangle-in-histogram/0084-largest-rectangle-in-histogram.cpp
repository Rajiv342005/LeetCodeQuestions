class Solution {
public:
    vector<int> leftSmallest(vector<int>nums){
        int n = nums.size();
        vector<int>NSL(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!st.empty()){
                // if stack top element is larger than current element;
                while(!st.empty() && nums[st.top()]>nums[i]){
                    st.pop();
                }
                if(!st.empty()) NSL[i] = st.top();
            }
            st.push(i);
        }
        return NSL;
    }
    vector<int> rightSmallest(vector<int>nums){
        int n = nums.size();
        vector<int>NSR(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!st.empty()){
                // if stack top element is greater than current element;
                if(nums[st.top()]>nums[i]){
                    while(!st.empty() && (nums[st.top()]>nums[i])){
                        NSR[st.top()] = i;
                        st.pop();
                    }
                }
            }
            st.push(i);
        }
        return NSR;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = leftSmallest(heights);
        vector<int>right = rightSmallest(heights);
        int maxArea = INT_MIN;
        int rectangleArea,breadth;
        for(int i=0;i<heights.size();i++){
            breadth = (right[i]-left[i]-1);
            rectangleArea = heights[i]*breadth;
            maxArea = max(maxArea,rectangleArea);
        }
        return maxArea;   
    }
};