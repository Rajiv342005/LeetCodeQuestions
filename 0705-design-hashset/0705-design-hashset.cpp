class MyHashSet {
    unordered_set<int>used;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        used.insert(key);
        return;    
    }
    
    void remove(int key) {
        used.erase(key);
        return;    
    }
    
    bool contains(int key) {
        if(used.find(key)!=used.end()) return true;
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