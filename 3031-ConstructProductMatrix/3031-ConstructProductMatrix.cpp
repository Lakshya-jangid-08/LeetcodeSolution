// Last updated: 6/29/2026, 10:20:48 AM
class Solution {
    int MOD = 12345;
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, 1));

        int prev = 1;
        int suff = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[i][j] = prev;
                prev = (1LL * prev * grid[i][j]) % MOD;
            }
        }

        for(int i = n -1; i>= 0; i--) {
            for(int j = m -1; j >= 0; j--) {
                res[i][j] = (1LL * res[i][j] * suff) % MOD;
                suff = (1LL * suff * grid[i][j]) % MOD;
            }
        }
        return res;
    }
};