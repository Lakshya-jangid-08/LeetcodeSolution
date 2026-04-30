// Last updated: 4/30/2026, 11:26:00 PM
1class Solution {
2    vector<vector<vector<int>>> dp;
3
4    int solve(int n , int m, vector<vector<int>> &grid, int k) {
5        if(k < 0) return -1e6;
6        if(n < 0 || m < 0) return -1e6;
7
8        if(n == 0 && m == 0) {
9            int cost = (grid[0][0] == 0 ? 0 : 1);
10            if(k >= cost) return grid[0][0];
11            return -1e6;
12        }
13
14        if(dp[n][m][k] != -1) return dp[n][m][k];
15
16        int cost = (grid[n][m] == 0 ? 0 : 1);
17
18        int up = solve(n - 1, m, grid, k - cost);
19        int left = solve(n, m - 1, grid, k - cost);
20
21        int best = max(up, left);
22
23        if(best == -1e6) return dp[n][m][k] = -1e6;
24
25        return dp[n][m][k] = best + grid[n][m];
26    }
27
28public:
29    int maxPathScore(vector<vector<int>>& grid, int k) {
30        int n = grid.size(), m = grid[0].size();
31
32        dp.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
33
34        int ans = solve(n - 1, m - 1, grid, k);
35
36        return (ans < 0 ? -1 : ans);
37    }
38};