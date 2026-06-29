// Last updated: 6/29/2026, 10:20:49 AM
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, U = 0;

        for (char &m : moves) {
            if (m == 'L') L++;
            else if (m == 'R') R++;
            else U++;
        }

        return abs(R - L) + U;
    }
};