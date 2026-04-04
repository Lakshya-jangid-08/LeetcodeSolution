// Last updated: 4/4/2026, 11:15:17 am
1class Solution {
2    using Minheap = priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> >;
3public:
4    int swimInWater(vector<vector<int>>& grid) {
5        Minheap pq;
6        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
7        pq.push({grid[0][0], {0, 0}});
8
9        int dx[] = {-1, 1, 0, 0};
10        int dy[] = {0, 0, -1, 1};
11
12        int time = 1e7;
13
14        while(!pq.empty()) {
15            auto [cost, cord] = pq.top();
16            pq.pop();
17
18            auto [x,y] = cord;
19            if(visit[x][y]) continue;
20            visit[x][y] = true;
21            if(x == grid.size() - 1 && y == grid[0].size() - 1) {
22                time = min(cost, time);
23                continue;
24            }
25
26            for(int i = 0; i < 4; i++) {
27                int u = x + dx[i];
28                int v = y + dy[i];
29
30                if(u < 0 || v < 0 || u >= grid.size() || v >= grid[0].size()) continue;
31                if(max(cost,grid[u][v]) > time) continue;
32                if(visit[u][v]) continue;
33                pq.push({ max(cost,grid[u][v]), {u, v}});
34
35            }
36
37        }
38        return time;
39    }
40};