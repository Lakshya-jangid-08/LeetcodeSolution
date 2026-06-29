// Last updated: 6/29/2026, 10:20:34 AM
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<int> freq(2, 0);

        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> prev(m, {0, 0});
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            vector<pair<int, int>> curr(m);
            for(int j = 0; j < m; j++) {
                auto up = prev[j];
                auto left = (j > 0) ? curr[j - 1] : pair<int,int>{0, 0};
                auto common = (j > 0) ? prev[j - 1] : pair<int,int>{0, 0};
                pair<int,int> p = {0, 0};
                if(grid[i][j] == 'X') {
                    p.first = 1;
                } else if(grid[i][j] == 'Y') {
                    p.second = 1;
                }
                curr[j] = { 
                    p.first + up.first + left.first - common.first,
                    p.second + up.second + left.second - common.second
                };
            }
            prev = curr;
            for(auto &[x, y] : prev) {
                if(x == y && x != 0) cnt++;
            }
        }  

        return cnt;
    }
};