// Last updated: 4/21/2026, 9:43:32 PM
1class Solution {
2public:
3    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
4        vector<int> parent(n, -1), rank(n, 0), weight(n, -1);
5        
6        const auto find = [&](auto && self, int node) -> int {
7            if(parent[node] == -1) return node;
8            return parent[node] = self(self, parent[node]);
9        };
10
11        const auto unite = [&](int u, int v, int w) {
12            int pu = find(find, u), pv = find(find, v);
13
14            if(pu == pv) {
15                weight[pv] = weight[pv] & w;
16                return;
17            }
18
19            if(rank[pu] < rank[pv]) {
20                rank[pv] += rank[pu];
21                parent[pu] = pv;
22                weight[pv] = weight[pu] & weight[pv] & w;
23            } else {
24                rank[pu] += rank[pv];
25                parent[pv] = pu;
26                weight[pu] = weight[pu] & weight[pv] & w;
27            }
28            return;
29        };
30
31        for(auto &e : edges) {
32            int u = e[0], v = e[1], w = e[2];
33            unite(u,v,w);
34        }
35
36        vector<int> res;
37        for(auto &q  : query) {
38            int src = q[0], dst = q[1];
39            int ps = find(find, src) , pd = find(find, dst);
40            if(ps != pd) res.push_back(-1);
41            else {
42                res.push_back(weight[ps]);
43            }
44        }
45        return res;
46    }
47};