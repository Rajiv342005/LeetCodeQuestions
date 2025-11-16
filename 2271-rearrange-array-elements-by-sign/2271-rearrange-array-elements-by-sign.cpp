class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>P;
        vector<int>N;
        for(int &val:nums){
            if(val>0) P.push_back(val);
            else N.push_back(val);
        }
        int pointer1=0;
        int pointer2=0;
        vector<int>ans;
        while(pointer1<P.size() && pointer2<N.size()){
            ans.push_back(P[pointer1++]);
            ans.push_back(N[pointer2++]);
        }
        while(pointer1<P.size()){
            ans.push_back(P[pointer1++]);
        }
        while(pointer2<N.size()){
            ans.push_back(N[pointer2++]);
        }
        return ans;
    }
};