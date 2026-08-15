class Solution {
public:
    int TimeTaken(int lastfloor, int curridx, vector<int>&requests){
        if(curridx == requests.size()) return 0;
        return abs(requests[curridx]-lastfloor)+TimeTaken(requests[curridx],curridx+1,requests);
    }
    int elevatorRequests(int n, vector<int>& requests) {
        return TimeTaken(0,0,requests);   
    }
};