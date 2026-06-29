// Last updated: 6/29/2026, 10:23:09 AM
class Solution {
    bool visit[301][301];
    
    void DFS(int x, int y, vector<vector<char>>& grid) {
        visit[x][y] = true;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX < 0 or newY < 0 or newY >= grid[0].size() or newX >= grid.size()) {
                continue;
            }
            if(visit[newX][newY] or grid[newX][newY] == '0')   continue;
            DFS(newX, newY, grid);
        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        memset(visit, false, sizeof(visit));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(!visit[i][j] && grid[i][j] == '1') {
                    DFS(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};