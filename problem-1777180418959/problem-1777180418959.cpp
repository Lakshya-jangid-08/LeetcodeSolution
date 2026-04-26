// Last updated: 4/26/2026, 10:43:38 AM
1class Solution {
2public:
3    bool containsCycle(vector<vector<char>>& grid) {
4        int n = grid.size(), m = grid[0].size();
5        vector<vector<bool>> visit(n, vector<bool>(m, false));
6        int dx[] = {-1, 1, 0, 0};
7        int dy[] = {0, 0, -1, 1};
8        for(int i = 0; i < n; i++) {
9            for(int j = 0; j < m; j++) {
10                if(visit[i][j]) continue;
11
12                queue<pair<int, int>> q;
13                q.push({i, j});
14
15                while(!q.empty()) {
16                    
17                    int len = q.size();
18                    while(len--) {
19                        auto [x, y] = q.front(); q.pop();
20
21                        if(visit[x][y]) return true;
22                        visit[x][y] = true;
23                        for(int k = 0; k < 4; k++) {
24                            int u = x + dx[k];
25                            int v = y + dy[k];
26                            if(u < 0 || v < 0 || u >= n || v >= m) continue;
27                            if(visit[u][v] || grid[i][j] != grid[u][v]) continue;
28                            q.push({u,v}); 
29                        }
30
31                    }
32
33                }
34
35            }
36        }
37        return false;
38    }
39};