// Last updated: 8/21/2026, 4:48:55 PM
1class Solution {
2public:
3    int numDistinct(string s, string t) {
4        
5        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
6
7        const auto solve = [&](auto && sol, int n, int m) -> int {
8            if(m == t.length()) return 1;
9            if(n == s.length()) return 0;
10
11            int &res = dp[n][m];
12            if(res != -1) return res;
13
14            res = 0;
15            if(s[n] == t[m]) {
16                res += sol(sol, n + 1, m + 1);
17            } 
18            res += sol(sol, n + 1, m);
19
20            return res;
21        };
22
23        return solve(solve, 0, 0);
24    }
25};