class Fancy {
public:
    vector<unsigned int>nums;
    unsigned int num = 1000000007;
    Fancy() {
        nums = {};
    }
    void append(int val) {
        nums.push_back(val);
        return;
    }
    void addAll(int inc) {
        for(int i=0;i<nums.size();i++){
            nums[i] = nums[i]+inc;
        }
        return;    
    }
    
    void multAll(int m) {
        for(int i=0;i<nums.size();i++){
            nums[i] = ((long long)nums[i]*m)%num;
        }
        return;     
    }
    
    int getIndex(int idx) {
        if(idx>=nums.size()) return -1;
        return nums[idx]%num;   
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */