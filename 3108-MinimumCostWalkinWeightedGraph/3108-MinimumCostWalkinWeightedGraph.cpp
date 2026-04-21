// Last updated: 4/21/2026, 9:37:01 PM
1class Solution {
2public:
3    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
4        int val = 1 << 20;
5        val--;
6        vector<int> parent(n), rank(n, 0), weight(n, val);
7        iota(parent.begin(), parent.end(), 0);
8        
9        const auto find = [&](auto && self, int x) -> int {
10            if(parent[x] == x) return x;
11            return parent[x] = self(self, parent[x]);
12        };
13
14        const auto unite = [&](int u, int v, int w) {
15            int pu = find(find, u), pv = find(find, v);
16
17            if(pu == pv) {
18                weight[pv] = weight[pv] & w;
19                return;
20            }
21
22            if(rank[pu] < rank[pv]) {
23                rank[pv] += rank[pu];
24                parent[pu] = pv;
25                weight[pv] = weight[pu] & weight[pv] & w;
26            } else {
27                rank[pu] += rank[pv];
28                parent[pv] = pu;
29                weight[pu] = weight[pu] & weight[pv] & w;
30            }
31            return;
32        };
33
34        for(auto &e : edges) {
35            int u = e[0], v = e[1], w = e[2];
36            unite(u,v,w);
37        }
38
39        vector<int> res;
40        for(auto &q  : query) {
41            int src = q[0], dst = q[1];
42            int ps = find(find, src) , pd = find(find, dst);
43            if(ps != pd) res.push_back(-1);
44            else {
45                res.push_back(weight[ps]);
46            }
47        }
48        return res;
49    }
50};