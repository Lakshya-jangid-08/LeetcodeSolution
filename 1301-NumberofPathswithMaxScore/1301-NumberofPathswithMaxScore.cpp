// Last updated: 7/21/2026, 5:37:14 PM
1class Solution {
2public:
3int MOD = 1e9 + 7;
4    vector<int> pathsWithMaxScore(vector<string>& board) {
5        int n = board.size(), m = board[0].length();
6        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
7        const auto solve = [&](auto &&self, int x, int y) -> vector<int> {
8            if(x == 0 && y == 0) {
9                return {0, 1};
10            }
11            if(x < 0 || y < 0) return {(int)-1e7 , 0};
12            if(board[x][y] == 'X') return {(int)-1e7, 0};
13
14            if(dp[x][y][0] != -1 && dp[x][y][1] != -1) return dp[x][y];
15
16            auto l = self(self, x, y - 1);
17            auto t = self(self, x - 1, y);
18            auto d = self(self, x - 1, y - 1);
19
20            int maxSum = max({l[0], t[0], d[0]});
21            long long path = 0;
22
23
24            if(l[0] == maxSum) path += 1LL * l[1];
25            if(t[0] == maxSum) path += 1LL * t[1];
26            if(d[0] == maxSum) path += 1LL * d[1];
27
28            if(board[x][y] != 'S') maxSum += board[x][y] - '0'; 
29
30            return dp[x][y] = {maxSum, (int)(path % MOD)};
31        };
32
33        auto res = solve(solve, n - 1, m - 1);
34        return (res[0] < 0) ? vector<int>{0, 0} : res;
35    }
36};