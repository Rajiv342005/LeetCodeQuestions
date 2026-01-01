class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        stack<int>st;
        vector<int>ans;
        int num = k;
        int index = nums.size()-1;
        int Sum=0;
        int Carry =0;
        while(index>=0 || num!=0){
            if(index<0){
                Sum = (num%10+Carry)%10;
                Carry = (num%10+Carry)/10;
            }
            else{
                Sum = (num%10+Carry+nums[index])%10;
                Carry = (num%10+Carry+nums[index])/10;
            }
            num = num/10;
            st.push(Sum);
            index--;
        }
        if(Carry!=0) st.push(Carry);
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};