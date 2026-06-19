class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest_altitude =0;
        int current_altitude =0;
        for(int num:gain){
            current_altitude+=num;
            highest_altitude = max(highest_altitude,current_altitude);
        }
        return highest_altitude;
    }
};