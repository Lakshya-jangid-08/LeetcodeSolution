// Last updated: 4/4/2026, 11:17:59 am
1class Solution {
2    using Minheap = priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> >;
3public:
4    int swimInWater(vector<vector<int>>& grid) {
5        Minheap pq;
6        int n = grid.size();
7        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
8        pq.push({grid[0][0], {0, 0}});
9
10        int dx[] = {-1, 1, 0, 0};
11        int dy[] = {0, 0, -1, 1};
12
13        while(!pq.empty()) {
14            auto [cost, cord] = pq.top();
15            pq.pop();
16
17            auto [x,y] = cord;
18            if(visit[x][y]) continue;
19            if(x == n-1 && y == n-1) return cost;
20            visit[x][y] = true;
21
22
23            for(int i = 0; i < 4; i++) {
24                int u = x + dx[i];
25                int v = y + dy[i];
26
27                if(u < 0 || v < 0 || u >= grid.size() || v >= grid[0].size()) continue;
28                if(visit[u][v]) continue;
29
30                pq.push({ max(cost,grid[u][v]), {u, v}});
31
32            }
33
34        }
35        return -1;
36    }
37};