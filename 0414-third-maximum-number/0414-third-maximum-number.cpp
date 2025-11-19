class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        stack<int>st;
        int index=0;
        st.push(nums[0]);
        while(index<nums.size()){
            if(st.size()!=3 && st.top()!=nums[index]){
                st.push(nums[index]);
                index++;
            }
            else{
                index++;
            }
        }
        if(st.size()==3) return st.top();
        return nums[0];    
    }
};