// Last updated: 6/29/2026, 10:21:37 AM
class Solution {
    unordered_map< int, unordered_map<int, pair<long long, long long>> > dp;
    pair<long long, long long> solve(vector<vector<int>>& grid, int n, int m) {
        if(n < 0 | m < 0) {
            return {1, -1};
        }
        if(n == 0 && m == 0) {
            return {grid[n][m], grid[n][m]};
        }

        if(dp[n].count(m)) return dp[n][m];

        auto down = solve(grid, n - 1, m);
        auto up = solve(grid , n, m - 1);
        auto res = up;
        if(grid[n][m] < 0) {
            res = {    
                1LL * grid[n][m] * max(down.second,up.second),
                1LL * grid[n][m] * min(down.first, up.first)
            };
        } else {
            res = {
                1LL * grid[n][m] * min(down.first, up.first),
                1LL * grid[n][m] * max(down.second,up.second)
            };
        }
        return dp[n][m] = res;
    }
public:
    int maxProductPath(vector<vector<int>>& grid) {
        auto res = solve(grid, grid.size()- 1, grid[0].size()-1);
        auto ans = max(res.second, res.first);
        int MOD = 1e9 + 7;
        return (ans < 0 ? -1 : ans % MOD);
    }
};