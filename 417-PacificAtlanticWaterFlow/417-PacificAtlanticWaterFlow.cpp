// Last updated: 8/12/2026, 10:17:08 PM
1class Solution {
2public:
3    int m, n;
4    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
5
6    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
7        m = heights.size();
8        n = heights[0].size();
9
10        vector<vector<bool>> pacific(m, vector<bool>(n, false));
11        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
12
13        for (int j = 0; j < n; j++) dfs(0, j, heights, pacific);
14        for (int i = 0; i < m; i++) dfs(i, 0, heights, pacific);
15
16        for (int j = 0; j < n; j++) dfs(m-1, j, heights, atlantic);
17        for (int i = 0; i < m; i++) dfs(i, n-1, heights, atlantic);
18
19        vector<vector<int>> result;
20        for (int i = 0; i < m; i++) {
21            for (int j = 0; j < n; j++) {
22                if (pacific[i][j] && atlantic[i][j]) {
23                    result.push_back({i, j});
24                }
25            }
26        }
27
28        return result;
29    }
30
31    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
32        visited[i][j] = true;
33        
34        for (auto& d : directions) {
35            int x = i + d[0], y = j + d[1];
36            
37            if (x < 0 || x >= m || y < 0 || y >= n) continue;
38            if (visited[x][y]) continue;
39            if (heights[x][y] < heights[i][j]) continue;
40            
41            dfs(x, y, heights, visited);
42        }
43    }
44};