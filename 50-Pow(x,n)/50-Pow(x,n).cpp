// Last updated: 4/14/2026, 3:42:54 PM
1class Solution {
2public:
3    double myPow(double x, int n) {
4        long long N = n;
5        if(N < 0) {
6            N = -N;
7            x = 1/x;
8        }
9        double ans = 1.0;
10        while(N > 0) {
11            if(N&1) {
12                ans *= x;
13            }
14            x *= x;
15            N = N >> 1;
16        }
17        return ans;
18
19    }
20};