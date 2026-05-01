class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    double median;
    MedianFinder() {   
    }
    
    void addNum(int num) {
        if(minheap.empty() && maxheap.empty()){
            median = num;
            maxheap.push(num);
        }
        else{
            if(num<=median) maxheap.push(num);
            else minheap.push(num);
        }
        median = findMedian();
        return;     
    }
    void heapbalance(){
        if(minheap.size()>1+maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else if(maxheap.size()>1+minheap.size()){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        return;
    }
    
    double findMedian() {
        if(abs((int)minheap.size()-(int)maxheap.size())>1)
        heapbalance();
        if(maxheap.size()==minheap.size()){
            median = (minheap.top()+maxheap.top())/2.0;
        }
        else if(minheap.size()>maxheap.size()) median = minheap.top();
        else median = maxheap.top();
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */