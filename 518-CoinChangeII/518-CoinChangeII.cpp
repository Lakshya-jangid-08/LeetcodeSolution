// Last updated: 7/28/2026, 2:50:00 PM
1class Solution {
2public:
3    int change(int amount, vector<int>& coins) {
4        int n = coins.size();
5        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
6
7        const auto solve = [&](auto &&self, int idx, int cash) -> int {
8            if(idx == n) return (cash == 0);
9            if(cash < 0) return 0;
10
11            if(dp[idx][cash] != -1) return dp[idx][cash];
12
13            int take = self(self, idx, cash - coins[idx]);            
14            int skip = self(self, idx + 1, cash);
15
16            return dp[idx][cash] = take + skip;
17        };
18
19        return solve(solve, 0, amount);
20    }
21};