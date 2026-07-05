class RecentCounter {
public:
    vector<int>recentCounter;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        recentCounter.push_back(t);
        int lowerbound = t-3000;
        int upperbound = t;
        int count = 0;
        for(auto time:recentCounter){
            if(time>=lowerbound && time<=upperbound) count++;
        }
        return count;   
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */