// Last updated: 7/5/2026, 9:25:33 PM
1struct node {
2    int point;
3    int x;
4    int y;
5
6    bool operator<(const node other) const {
7        if (point != other.point) return point < other.point;
8        if (x != other.x) return x < other.x;
9        return y < other.y;
10    }
11};
12class Solution {
13public:
14    bool findSafeWalk(vector<vector<int>>& grid, int health) {
15        //  brute force - recursion - 3 ^ NM;
16
17        priority_queue< node > pq;
18        int n = grid.size(), m = grid[0].size();
19        pq.push({health - grid[0][0], 0, 0});
20        vector<vector<int>> vis(n, vector<int>(m, 0));
21        vis[0][0] = 1;
22
23        int dx[] = {-1, 1, 0, 0};
24        int dy[] = {0, 0, -1, 1};
25
26        while(!pq.empty()) {
27
28            auto topElem = pq.top(); pq.pop();
29            int point = topElem.point, x = topElem.x, y = topElem.y;
30
31            if(point <= 0) return false;
32            if(x == n - 1 && y == m - 1) return true;
33
34            for(int i = 0; i < 4; i += 1) {
35                int nx = x + dx[i];
36                int ny = y + dy[i];
37
38                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
39                if(vis[nx][ny] || point - grid[nx][ny] <= 0) continue;
40                vis[nx][ny] = 1;
41                pq.push({point - grid[nx][ny], nx, ny});
42            }
43        }
44
45        return false;
46    }
47};