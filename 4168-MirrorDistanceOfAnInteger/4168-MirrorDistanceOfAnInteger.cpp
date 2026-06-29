// Last updated: 6/29/2026, 10:19:57 AM
class Solution {
public:
    int revnum(int a) {
        if (a / 10 == 0) return a ;
        string s = to_string(a);
        reverse(s.begin(), s.end()) ;
        return stoi(s) ;
    }

    int mirrorDistance(int n) {
        return abs(n - revnum(n)) ;
    }
};