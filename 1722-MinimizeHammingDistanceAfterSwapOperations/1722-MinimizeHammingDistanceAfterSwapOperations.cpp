// Last updated: 4/21/2026, 8:50:58 PM
1class Solution {
2public:
3    int minimumHammingDistance(vector<int>& src, vector<int>& dst, vector<vector<int>>& as) {
4        int n = src.size();
5        vector<int> parent(n), rank(n, 0);
6        iota(parent.begin(), parent.end(), 0);
7
8        const auto find = [&](auto && self, int x) -> int {
9            if(parent[x] == x) return x;
10            return parent[x] = self(self, parent[x]);
11        };
12
13        const auto unite = [&](int u, int v) {
14            int pu = find(find, u);
15            int pv = find(find, v);
16
17            if(pu == pv) return;
18
19            if(rank[pu] < rank[pv]) {
20                rank[pv] += rank[pu];
21                parent[pu] = pv;
22            } else {
23                rank[pu] += rank[pv];
24                parent[pv] = pu;
25            }
26            return;
27        };
28
29        for(auto &it : as) {
30            unite(it[0], it[1]);
31        }
32
33        unordered_map<int , unordered_map<int, int>> IdxMP;
34
35        for(int i = 0; i < n; i++) {
36            int p = find(find, i);
37            IdxMP[p][src[i]]++;
38        }
39
40        int res = 0;
41
42        for(int i = 0; i < n; i++) {
43            int f = find(find, i);
44            if(IdxMP[f].count(dst[i]) == 0) {
45                res++;
46                continue;
47            }
48            IdxMP[f][dst[i]]--;
49            if(IdxMP[f][dst[i]] == 0) {
50                IdxMP[f].erase(dst[i]);
51            }
52        }
53
54        return res;
55    }
56};