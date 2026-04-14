// Last updated: 4/14/2026, 3:58:24 PM
1class Solution {
2public:
3    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
4        int m = obstacleGrid.size();
5        int n = obstacleGrid[0].size();
6
7        vector<int> curr(n), prev(n, 0);
8
9        curr[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
10
11        for(int i = 0; i < m; i++) {
12            for(int j = 0; j < n; j++) {
13                if(i == 0 && j == 0) continue;
14                int up  = 0, left = 0;
15
16                if(i - 1 >= 0) up = prev[j];
17                if(j - 1 >= 0) left = curr[j-1];
18                
19                if(obstacleGrid[i][j] == 0)
20                    curr[j] = up + left;
21                else curr[j] = 0;
22            }
23            prev = curr;
24        }
25        return prev[n - 1];
26    }
27};