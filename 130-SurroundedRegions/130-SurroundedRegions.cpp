// Last updated: 6/29/2026, 10:23:24 AM
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        const auto dfs = [&](auto &&self, int x, int y) {
            if(x < 0 || y < 0 || x >= n || y >= m || board[x][y] == 'X') return;
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
            if(board[i][0] == 'O')
                dfs(dfs, i, 0);
            if(board[i][m-1] == 'O')
                dfs(dfs, i, m -1);
        }

        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') 
                dfs(dfs, 0, j);
            if(board[n - 1][j] == 'O')
                dfs(dfs, n - 1, j);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j]) continue;
                board[i][j] = 'X';
            }
        }
        return;
    }
};