class Solution {
public:
    int conversion(string &s,int start){
        int num = 0;
        num = num*10 + (s[start]-'0');
        num = num*10 + (s[start+1]-'0');
        return num;
    }
    void vacationfilling(string &arrive,string &leave,vector<vector<bool>>&calender){
        int startDay = conversion(arrive,3);
        int startMonth = conversion(arrive,0);
        int lastDay = conversion(leave,3);
        int lastMonth = conversion(leave,0);
        vector<int>DaysOnMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(startMonth == lastMonth){
            for(int i=startDay; i<=lastDay;i++){
                calender[startMonth-1][i-1] = 1;
            }
            return;
        };
        for(int i=startDay; i<=DaysOnMonth[startMonth-1];i++){
            calender[startMonth-1][i-1] = 1;
        }
        for(int i=1; i<=lastDay;i++){
            calender[lastMonth-1][i-1] = 1;
        }
        for(int i=startMonth+1; i<lastMonth; i++){
            for(int j=0;j<DaysOnMonth[i-1];j++){
                calender[i-1][j] = 1;
            }
        }
        return;    
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<vector<bool>>aliceRomeCalender(12,vector<bool>(31,0));
        vector<vector<bool>>BobRomeCalender(12,vector<bool>(31,0));
        vacationfilling(arriveAlice,leaveAlice,aliceRomeCalender);
        vacationfilling(arriveBob,leaveBob,BobRomeCalender);
        int totalDays = 0;
        for(int month=0;month<12;month++){
            for(int day=0;day<31;day++){
                if(aliceRomeCalender[month][day] && BobRomeCalender[month][day]) totalDays++;
            }
        }
        return totalDays;     
    }
};