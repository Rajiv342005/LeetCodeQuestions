class NumArray {
public:
    vector<int>prefixSum;
    vector<int>arr;
    NumArray(vector<int>& nums) {
        arr = nums;
        prefixSum.resize(nums.size()+1);
        prefixSum[0] = 0;
        for(int i=1;i<=nums.size();i++){
            prefixSum[i] = prefixSum[i-1]+nums[i-1];
        }    
    }
    
    void update(int index, int val) {
        int diff = val-arr[index];
        arr[index] = val;
        for(int i=index+1;i<prefixSum.size();i++){
            prefixSum[i] += diff;
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1]-prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */