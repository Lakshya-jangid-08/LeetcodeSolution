// Last updated: 7/25/2026, 1:58:03 PM
1class Solution {
2public:
3    int maxProduct(int n) {
4        int mx1 = 0, mx2 = 0;
5
6        while(n > 0) {
7            int dig = n % 10;
8            n /= 10;
9            if(dig > mx1) {
10                mx2 = mx1;
11                mx1 = dig;
12            } else if(dig > mx2) {
13                mx2 = dig;
14            }
15        }
16        return mx1 * mx2;
17
18    }
19};