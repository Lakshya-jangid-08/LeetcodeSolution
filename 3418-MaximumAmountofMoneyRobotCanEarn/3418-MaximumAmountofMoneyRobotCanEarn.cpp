// Last updated: 2/4/2026, 10:29:21 am
1class Solution {
2public:
3    int maximumAmount(vector<vector<int>>& coins) {
4        int n = coins[0].size();
5
6        vector<vector<int>> prev(n + 1, vector<int>(3, -1e7));
7
8        prev[1][0] = 0;
9        prev[1][1] = 0;
10        prev[1][2] = 0;
11
12        for(auto &row : coins) {
13            // curr 
14
15            for(int j = 1; j <= n; j++) {
16                // 0 means no neu.
17                prev[j][2] = max({
18                    row[j - 1] + prev[j - 1][2],
19                    row[j - 1] + prev[j][2],
20                    prev[j - 1][1],
21                    prev[j][1],
22                });
23                prev[j][1] = max({
24                    row[j - 1] + prev[j - 1][1],
25                    row[j - 1] + prev[j][1],
26                    prev[j - 1][0],
27                    prev[j][0]
28                });
29                prev[j][0] = max(row[j - 1] + prev[j][0], row[j - 1] + prev[j - 1][0]);
30
31            }
32
33        }
34        return prev[n][2];
35    }
36};