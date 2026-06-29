// Last updated: 6/29/2026, 10:20:31 AM
class Solution {
    int dp[301][301][16];
    int MOD = 1e9 + 7;
    int solve(vector<vector<int>> &grid, int x, int y, int currXor, int k) {
        if(x >= grid.size() || y >= grid[0].size()) return 0;
        currXor = currXor ^ grid[x][y];
        
        if(x == grid.size() - 1 && y == grid[0].size() - 1) {
            return (currXor == k);
        }
        
        if(dp[x][y][currXor] != -1) return dp[x][y][currXor];

        int down = solve(grid, x + 1, y, currXor, k);
        int right = solve(grid, x, y + 1, currXor, k);
        dp[x][y][currXor] = (down + right) % MOD;

        return dp[x][y][currXor];
    }

public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, 0, k);
    }
};