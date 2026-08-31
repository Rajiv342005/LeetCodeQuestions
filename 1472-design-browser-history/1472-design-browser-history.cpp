class BrowserHistory {
public:
    stack<string>CurrentTab;
    stack<string>ForwardTab;
    BrowserHistory(string homepage) {
        CurrentTab.push(homepage);
    }
    void visit(string url) {
        CurrentTab.push(url);
        ForwardTab = stack<string>();
    }
    
    string back(int steps) {
        string url = "";
        while(!CurrentTab.empty() && steps!=0){
            url = CurrentTab.top();
            ForwardTab.push(url);
            CurrentTab.pop();
            steps--;
        }
        if(CurrentTab.empty()){
            CurrentTab.push(url);
            ForwardTab.pop();
        }
        return CurrentTab.top();
    }
    
    string forward(int steps) {
        while(!ForwardTab.empty() && steps!=0){
            CurrentTab.push(ForwardTab.top());
            ForwardTab.pop();
            steps--;
        }
        return CurrentTab.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */