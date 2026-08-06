// Last updated: 8/6/2026, 9:29:08 AM
1class Solution {
2public:
3    int smallestNumber(int n, int t) {
4        for(int num = n; num <= n * t; num++) {
5            const auto solve = [](int n) -> int {
6                if (n == 0) return 0;
7
8                int prod = 1;
9                while (n > 0) {
10                    prod *= (n % 10);
11                    n /= 10;
12                }
13                return prod;
14            };
15            int val = solve(num);
16            if(val % t == 0) return num; 
17            // cout << val;
18        } 
19        return -1;
20    }
21};