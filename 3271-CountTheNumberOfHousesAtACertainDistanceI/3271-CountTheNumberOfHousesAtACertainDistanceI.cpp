// Last updated: 6/29/2026, 10:20:44 AM
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        
        vector<vector<int>> grid(n + 1, vector<int>(n + 1, 1e9));

        for(int i = 1; i < n; i++) {
            grid[i][i + 1] = 1;
            grid[i + 1][i] = 1;
        }
        grid[x][y] = 1;
        grid[y][x] = 1;

        for(int via = 1; via <= n; via++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(i == j) grid[i][j] = 0;
                    else {
                        grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                    }
                }
            }
        }

        vector<int> res;
        for(int k = 1; k <= n; k++) {
            int cnt = 0;
            for(int i = 0; i <= n; i++) {
                for(int j = 0; j <= n; j++) {
                    if(k == grid[i][j]) cnt++;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};