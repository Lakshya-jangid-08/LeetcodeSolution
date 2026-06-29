// Last updated: 6/29/2026, 10:20:24 AM
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> res(n - k + 1, vector<int>(m - k + 1, -1));

        auto calc = [&](int x, int y) -> vector<int> {
            int res = 0;
            vector<int> temp;
            for(int i = x; i < x + k; i++) {
                for(int j = y; j < y + k; j++) {
                    temp.push_back(grid[i][j]);
                }
            }
            return temp;
        };
        
        for(int i = 0; i < n - k + 1; i++) {
            for(int j = 0; j < m - k + 1; j++) {
                auto temp = calc(i, j);
                sort(temp.begin(), temp.end());
                int ans = 1e8;
                for(int t = 0; t < temp.size() - 1; t++) {
                    if(temp[t] == temp[t + 1]) continue;
                    ans = min(ans, temp[t + 1] - temp[t]);
                } 
                res[i][j] = (ans==1e8?0:ans);
            }
        }
        return res;
    }
};