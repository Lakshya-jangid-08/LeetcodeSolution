// Last updated: 6/29/2026, 10:22:12 AM
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string temp = s + s;
        return (temp.contains(goal));
    }
};