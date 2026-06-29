// Last updated: 6/29/2026, 10:21:58 AM
class Solution {

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        const auto dfs = [&](auto &&self, int x, int y) {
            if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0) return;
            if(vis[x][y]) return;
            vis[x][y] = true;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                self(self, nx, ny);
            }
            return;
        };

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1)
                dfs(dfs, i, 0);
            if(grid[i][m-1] == 1)
                dfs(dfs, i, m -1);
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1) 
                dfs(dfs, 0, j);
            if(grid[n - 1][j] == 1)
                dfs(dfs, n - 1, j);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] || grid[i][j] == 0) continue;
                cnt++;
            }
        }
        return cnt;
    }
};