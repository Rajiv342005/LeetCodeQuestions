class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flip =0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!q.empty()&&q.front()==i-k)
            q.pop();
            if(q.size()%2==nums[i]){
                if(i+k>n) return -1;
                flip++;
                q.push(i);
            }
        }
        return flip;
    }
};