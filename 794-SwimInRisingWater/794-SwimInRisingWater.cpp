// Last updated: 6/29/2026, 10:22:17 AM
class Solution {
    using Minheap = priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> >;
public:
    int swimInWater(vector<vector<int>>& grid) {
        Minheap pq;
        int n = grid.size();
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        pq.push({grid[0][0], {0, 0}});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty()) {
            auto [cost, cord] = pq.top();
            pq.pop();

            auto [x,y] = cord;
            if(visit[x][y]) continue;
            if(x == n-1 && y == n-1) return cost;
            visit[x][y] = true;


            for(int i = 0; i < 4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];

                if(u < 0 || v < 0 || u >= grid.size() || v >= grid[0].size()) continue;
                if(visit[u][v]) continue;

                pq.push({ max(cost,grid[u][v]), {u, v}});

            }

        }
        return -1;
    }
};