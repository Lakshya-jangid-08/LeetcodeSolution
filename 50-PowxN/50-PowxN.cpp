// Last updated: 6/29/2026, 10:23:41 AM
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0) {
            N = -N;
            x = 1/x;
        }
        double ans = 1.0;
        while(N > 0) {
            if(N&1) {
                ans *= x;
            }
            x *= x;
            N = N >> 1;
        }
        return ans;

    }
};