class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ClockWise = abs(30*hour-5.5*minutes);
        double AntiClockWise = 360-ClockWise;
        return min(ClockWise,AntiClockWise);
    }
};