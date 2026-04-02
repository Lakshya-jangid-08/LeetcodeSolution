// Last updated: 3/4/2026, 1:22:09 am
1class Solution {
2public:
3    vector<int> countOfPairs(int n, int x, int y) {
4        
5        vector<vector<int>> grid(n + 1, vector<int>(n + 1, 1e9));
6
7        for(int i = 1; i < n; i++) {
8            grid[i][i + 1] = 1;
9            grid[i + 1][i] = 1;
10        }
11        grid[x][y] = 1;
12        grid[y][x] = 1;
13
14        for(int via = 1; via <= n; via++) {
15            for(int i = 1; i <= n; i++) {
16                for(int j = 1; j <= n; j++) {
17                    if(i == j) grid[i][j] = 0;
18                    else {
19                        grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
20                    }
21                }
22            }
23        }
24
25        vector<int> res;
26        for(int k = 1; k <= n; k++) {
27            int cnt = 0;
28            for(int i = 0; i <= n; i++) {
29                for(int j = 0; j <= n; j++) {
30                    if(k == grid[i][j]) cnt++;
31                }
32            }
33            res.push_back(cnt);
34        }
35        return res;
36    }
37};