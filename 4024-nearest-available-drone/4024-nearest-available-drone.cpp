class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mindist = INT_MAX;
        int idx = -1;
        int Xcord,Ycord,Range,ManhattanDist;
        for(int i=0;i<drones.size();i++){
            Xcord = drones[i][0];
            Ycord = drones[i][1];
            Range = drones[i][2];
            ManhattanDist = abs(Xcord-target[0])+abs(Ycord-target[1]);
            if(ManhattanDist<=Range && ManhattanDist<mindist){
                mindist = ManhattanDist;
                idx = i;
            }    
        }
        return idx;
    }
};