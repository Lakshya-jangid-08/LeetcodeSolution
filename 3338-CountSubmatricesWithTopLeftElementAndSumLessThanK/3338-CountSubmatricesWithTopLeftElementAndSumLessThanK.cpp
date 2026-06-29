// Last updated: 6/29/2026, 10:20:40 AM
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int prev = (j > 0) ? grid[i][j - 1] : 0;
                int up = (i > 0) ? grid[i - 1][j] : 0;
                int cmn = (i > 0 && j > 0) ? grid[i - 1][j - 1] : 0;
                grid[i][j] = grid[i][j] + prev + up - cmn;
            }
        }

        int cnt = 0;
        for(auto &row : grid) {
            for(auto &val : row) {
                if(val <= k) cnt++;
            }
        }
        return cnt;
    }
};