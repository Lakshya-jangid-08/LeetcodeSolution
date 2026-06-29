// Last updated: 6/29/2026, 10:20:13 AM
class Solution {
    vector<vector<vector<int>>> dp;

    int solve(int n , int m, vector<vector<int>> &grid, int k) {
        if(k < 0) return -1e6;
        if(n < 0 || m < 0) return -1e6;

        if(n == 0 && m == 0) {
            int cost = (grid[0][0] == 0 ? 0 : 1);
            if(k >= cost) return grid[0][0];
            return -1e6;
        }

        if(dp[n][m][k] != -1) return dp[n][m][k];

        int cost = (grid[n][m] == 0 ? 0 : 1);

        int up = solve(n - 1, m, grid, k - cost);
        int left = solve(n, m - 1, grid, k - cost);

        int best = max(up, left);

        if(best == -1e6) return dp[n][m][k] = -1e6;

        return dp[n][m][k] = best + grid[n][m];
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));

        int ans = solve(n - 1, m - 1, grid, k);

        return (ans < 0 ? -1 : ans);
    }
};