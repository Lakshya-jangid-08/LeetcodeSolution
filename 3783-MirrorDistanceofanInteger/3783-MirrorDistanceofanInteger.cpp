// Last updated: 4/18/2026, 10:22:19 AM
1class Solution {
2public:
3    int mirrorDistance(int n) {
4        string s = to_string(n);
5        reverse(s.begin(), s.end());
6        return abs(n - stoi(s));
7    }
8};