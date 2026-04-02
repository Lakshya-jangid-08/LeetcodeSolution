// Last updated: 2/4/2026, 10:14:16 am
1class Solution {
2public:
3    int maximumAmount(vector<vector<int>>& coins) {
4        int n = coins.size();
5        int m = coins[0].size();
6        int minVal = -1e9;
7
8        vector<vector<int>> prev(m, vector<int>(3, minVal));
9        prev[0][0] = coins[0][0];
10
11        if(coins[0][0] < 0) 
12            prev[0][1] = 0;
13
14        for(int y = 1; y < m; y++) {
15            for(int cnt = 0; cnt < 3; cnt++) {
16                int res = minVal;
17                res = max(res, coins[0][y] + prev[y - 1][cnt]);
18                if(coins[0][y] < 0 && cnt > 0)
19                    res = max(res, prev[y - 1][cnt - 1]);
20                prev[y][cnt] = res;
21            }
22        }
23
24        for(int x = 1; x < n; x++) {
25            vector<vector<int>> curr(m, vector<int>(3, minVal));
26
27            for(int y = 0; y < m; y++) {
28                for(int cnt = 0; cnt < 3; cnt++) {
29
30                    int res = minVal;
31                    res = max(res, coins[x][y] + prev[y][cnt]);
32                    res = max(res, coins[x][y] + (y == 0 ? minVal : curr[y - 1][cnt]));
33
34                    // skip negative
35                    if(coins[x][y] < 0 && cnt > 0) {
36                        res = max(res, prev[y][cnt - 1]);
37                        res = max(res, (y == 0 ? minVal : curr[y - 1][cnt - 1]));
38                    }
39
40                    curr[y][cnt] = res;
41                }
42            }
43            prev = curr;
44        }
45
46        return max({prev[m - 1][0], prev[m - 1][1], prev[m - 1][2]});
47    }
48};