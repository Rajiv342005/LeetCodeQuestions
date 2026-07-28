class MyHashSet {
public:
    vector<pair<int,bool>>nums;
    MyHashSet() {
        
    }
    void add(int key) {
        for(auto &it:nums){
            if(it.first==key){
                it.second = true;
                return;
            }
        }
        nums.push_back({key,true});
        return; 
    }
    
    void remove(int key) {
        for(auto &it:nums){
            if(it.first==key){
                it.second = false;
            }
        }
        return;    
    }
    
    bool contains(int key) {
        for(auto &it: nums){
            if(it.first==key){
                return it.second;
            }
        }
        return false;   
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */