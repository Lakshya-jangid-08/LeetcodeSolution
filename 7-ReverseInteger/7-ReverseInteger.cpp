// Last updated: 12/4/2026, 12:54:07 pm
1class Solution {
2public:
3    int reverse(int temp) {
4        long long res = 0;
5        long long mult = 1;
6        long long x = temp;
7        if(x < 0) {
8            mult = -1;
9            x = - 1LL * temp;
10        }
11        while(x > 0) {
12            res = res * 10 + (x % 10);
13            if(res > INT_MAX || res < INT_MIN) return 0;
14            x /= 10;
15        }
16        return res * mult;
17    }
18};