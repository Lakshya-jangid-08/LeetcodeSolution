// Last updated: 8/11/2026, 12:12:07 AM
1class Solution {
2public:
3    bool winnerSquareGame(int n) {
4        vector<int> dp(n + 1, - 1);
5        const auto solve = [&](auto &&self, int cost) -> bool {
6            int mxv = sqrt(cost);
7            int& res = dp[cost];
8
9            if(res != -1) return res;
10            res = 0;
11            for(int i = 1; i <= mxv; i++) {
12                res |= !self(self, cost - i * i);
13            }
14            return res;
15        };
16
17        return solve(solve, n);
18    }
19};