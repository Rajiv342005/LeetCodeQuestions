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

    int largestRectangleArea(vector<int>&height){
        vector<int>left = leftSmallest(height);
        vector<int>right = rightSmallest(height);
        int maxArea = 0;
        int rectangleArea,breadth;
        for(int i=0;i<height.size();i++){
            breadth = (right[i]-left[i]-1);
            rectangleArea = height[i]*breadth;
            maxArea = max(maxArea,rectangleArea);
        }
        return maxArea;
    } 
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>heights(n,0);
        int maxArea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') heights[j] = 0;
                else heights[j] += 1;
            }
            maxArea = max(maxArea,largestRectangleArea(heights));
        }
        return maxArea;
    }
};