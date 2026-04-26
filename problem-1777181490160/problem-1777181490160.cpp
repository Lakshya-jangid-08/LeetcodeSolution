// Last updated: 4/26/2026, 11:01:30 AM
1class Solution {
2public:
3    bool containsCycle(vector<vector<char>>& grid) {
4        int n = grid.size(), m = grid[0].size();
5        vector<int> parent(m * n + 1), size(m * n + 1, 1);
6        iota(parent.begin(), parent.end(), 0);
7
8        const auto find = [&](auto self, int x) -> int {
9            if(parent[x] == x) return x;
10            return parent[x] = self(self, parent[x]);
11        };
12
13        const auto unite = [&](int u, int v) -> bool {
14            int pu = find(find, u);
15            int pv = find(find, v);
16
17            if(pu == pv) return true;
18
19            if(size[pu] < size[pv]) {
20                size[pv] += size[pu];
21                parent[pu] = pv;
22            } else {
23                size[pu] += size[pv];
24                parent[pv] = pu;
25            }
26            return false;
27        };
28
29        for(int i = 0; i < n; i++) {
30            for(int j = 0; j < m; j++) {
31
32                if(i > 0 && grid[i][j] == grid[i - 1][j]) {
33                    bool res = unite(i + j * n, i + j * n - 1);
34                    if(res) return true;
35                } 
36                if(j > 0 && grid[i][j] == grid[i][j - 1]) {
37                    bool res = unite(i + j * n, i + (j - 1) * n);
38                    if(res) return true;
39                }
40
41            }
42        }
43        return false;
44
45    }
46};