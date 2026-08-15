class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int totaltime = 0;
        int last = 0;
        for(int req: requests){
            totaltime += abs(req-last);
            last = req; 
        }
        return totaltime;
    }
};