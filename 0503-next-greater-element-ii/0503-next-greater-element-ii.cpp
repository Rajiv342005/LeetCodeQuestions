class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack <int> st;
        int index =0;
        vector<int> temp(n,-1);
        int curr=0;
        while(index <2*n){
            curr = nums[index%n];
            while (!st.empty() && nums[st.top()] < curr) {
                temp[st.top()] = curr;
                st.pop();
            }
            if(index<n){
                st.push(index);
                index++;
            }
            else{
                index++;
            }
        }
        return temp;
    }
};