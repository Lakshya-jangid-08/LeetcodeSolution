// Last updated: 8/21/2026, 10:12:07 PM
1class Solution {
2public:
3    int commonFactors(int a, int b) {
4        int n = min(a, b);
5        // n = sqrt(n);
6
7        int count = 0;
8        for(int i = 1; i <= n; i++) {
9            if(a % i || b % i) continue;
10            count += 1;
11        }
12        return count;
13    }
14};