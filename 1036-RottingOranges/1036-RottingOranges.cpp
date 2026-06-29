// Last updated: 6/29/2026, 10:22:01 AM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    fresh += 1;
                } else if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        if(fresh == 0) return 0;

        int rotten = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                auto [x, y] = q.front(); q.pop();

                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1) continue;
                    fresh--;
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }

            }
            rotten += 1;
        }
        return (fresh > 0) ? -1 : rotten - 1;
    }
};