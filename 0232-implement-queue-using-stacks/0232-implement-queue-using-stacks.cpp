class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>st1; //Hamesha isme Element rakhenge;
    stack<int>st2;  // Isme Sirf Push or Pop ke samay isme Rakhenge.
    void push(int x) {
        st1.push(x);
    }
    int pop() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int data = st2.top();
        st2.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return data;
    }
    
    int peek() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int data = st2.top();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return data;   
    }
    
    bool empty() {
        if(st1.empty() && st2.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */