// Last updated: 6/29/2026, 10:21:47 AM
class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double minDeg = 6.0 * minutes;
        double hourDeg = (minutes / 60.0) * 30 + hour * 30;
        double res = abs(hourDeg - minDeg);
        return min(res, 360 - res); 
    }
};