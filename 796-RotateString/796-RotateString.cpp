// Last updated: 5/3/2026, 9:50:16 AM
1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        if(s.length() != goal.length()) return false;
5        string temp = s + s;
6        return (temp.contains(goal));
7    }
8};