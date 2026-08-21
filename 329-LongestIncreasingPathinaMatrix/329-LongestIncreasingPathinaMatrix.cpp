// Last updated: 8/21/2026, 9:59:16 PM
1class Solution {
2public:
3    int longestIncreasingPath(vector<vector<int>>& matrix) {
4        int n = matrix.size(), m = matrix[0].size();
5
6        vector<vector<int>> visit(n, vector<int>(m , 0));
7        int dx[] = {-1, 1, 0, 0};
8        int dy[] = {0, 0, -1, 1};
9
10        const auto solve = [&](auto && sol, int x, int y) -> int {
11
12            if(visit[x][y] != 0) return visit[x][y];
13            visit[x][y] = 1;
14            int best = 0;
15            for(int i = 0; i < 4; i++) {
16                int nx = x + dx[i];
17                int ny = y + dy[i];
18
19                if(nx < 0 || ny < 0) continue;
20                if(nx >= n || ny >= m) continue;
21                if(matrix[x][y] >= matrix[nx][ny]) continue;
22
23                best = max(best, sol(sol, nx, ny));
24            }
25            return visit[x][y] += best;
26        };
27
28        int path = 0;
29        for(int i = 0; i < n; i++) {
30            for(int j = 0; j < m; j++) {
31                path = max(path, solve(solve, i, j));
32            }
33        }
34        return path;
35    }
36};