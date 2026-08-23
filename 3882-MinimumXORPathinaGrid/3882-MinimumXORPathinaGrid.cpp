// Last updated: 8/23/2026, 6:40:52 PM
1class Solution {
2public:
3    int minCost(vector<vector<int>>& grid) {
4        int n = grid.size(), m = grid[0].size();
5
6        vector<vector<unordered_set<int>>> dp(n, vector<unordered_set<int>>(m));
7        for(int i = 0; i < n; i++) {
8            for(int j = 0; j < m; j++) {
9                if(i == 0 && j == 0) {
10                    dp[i][j].insert(grid[0][0]);
11                    continue;;
12                }
13                if(i > 0)
14                    for(const int x : dp[i - 1][j]) {
15                        int a = x ^ grid[i][j];
16                        dp[i][j].insert(a);
17                    }
18                if(j > 0)
19                    for(const int x : dp[i][j - 1]) {
20                        int b = x ^ grid[i][j];
21                        dp[i][j].insert(b);
22                    }
23            }
24        }
25
26        int res = 1e8;
27        for(const int i : dp[n-1][m-1]) 
28            res = min(res, i);
29
30        return res; 
31    }
32};