// Last updated: 6/29/2026, 10:21:39 AM
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> parent(m * n + 1), size(m * n + 1, 1);
        iota(parent.begin(), parent.end(), 0);

        const auto find = [&](auto self, int x) -> int {
            if(parent[x] == x) return x;
            return parent[x] = self(self, parent[x]);
        };

        const auto unite = [&](int u, int v) -> bool {
            int pu = find(find, u);
            int pv = find(find, v);

            if(pu == pv) return true;

            if(size[pu] < size[pv]) {
                size[pv] += size[pu];
                parent[pu] = pv;
            } else {
                size[pu] += size[pv];
                parent[pv] = pu;
            }
            return false;
        };

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(i > 0 && grid[i][j] == grid[i - 1][j]) {
                    bool res = unite(i + j * n, i + j * n - 1);
                    if(res) return true;
                } 
                if(j > 0 && grid[i][j] == grid[i][j - 1]) {
                    bool res = unite(i + j * n, i + (j - 1) * n);
                    if(res) return true;
                }

            }
        }
        return false;

    }
};