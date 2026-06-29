// Last updated: 6/29/2026, 10:19:32 AM
class Solution {
public:
    string trafficSignal(int timer) {
        if(timer == 0) return "Green";
        if(timer == 30) return "Orange";
        if(timer > 30 && timer <= 90) return "Red";
        return "Invalid";
    }
};