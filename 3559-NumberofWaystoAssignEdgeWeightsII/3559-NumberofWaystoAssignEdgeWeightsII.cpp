// Last updated: 8/22/2026, 11:33:58 AM
1class Solution {
2public:
3    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
4        int n = edges.size() + 1;
5        int col = log2(n) + 1;
6        vector<vector<int>> parent(n + 1, vector<int>(col, -1));
7        vector<int> depth(n + 1, 0);
8
9        vector<vector<int>> adj(n + 1);
10
11        for(auto &ed : edges) {
12            int u = ed[0], v = ed[1];
13            adj[u].push_back(v);
14            adj[v].push_back(u);
15        }
16
17        vector<bool> visit(n + 1, 0);
18        const auto dfs = [&](auto &&func, int root, int par, int d = 0) {
19            if(visit[root]) return;
20            visit[root] = 1;
21            parent[root][0] = par;
22            depth[root] = d;
23
24            for(auto &nextNode : adj[root]) {
25                func(func, nextNode, root, d + 1);
26            }
27        };
28
29        dfs(dfs, 1, -1);
30
31        for(int i = 1; i < col; i++) {
32            for(int node = 0; node <= n; node++) {
33                int mid = parent[node][i - 1];
34                if(mid != -1) 
35                    parent[node][i] = parent[mid][i - 1];
36            }
37        }
38
39        const auto findLCA = [&](int u, int v) -> int {
40
41            const auto makeEqual = [&](int &u, int &v) {
42                
43                const auto findKthAncestor = [&](int node, int k) -> int {
44                    for(int i = col - 1; i >= 0; i--) {
45                        if(k & (1 << i)) {
46                            node = parent[node][i];
47                        }
48                        if(node == -1) return node;
49                    }
50                    return node;
51                };
52
53                int ud = depth[u], vd = depth[v];
54                int diff = ud - vd;
55                if(diff > 0) {
56                    u = findKthAncestor(u, diff);
57                } else if(diff < 0) {
58                    v = findKthAncestor(v, -diff);
59                }
60            };
61
62            makeEqual(u, v);
63            if(u == v) return u;
64
65            for(int i = col - 1; i >= 0; i--) {
66                if(parent[u][i] != parent[v][i]) {
67                    u = parent[u][i];
68                    v = parent[v][i];
69                }
70            }
71            return parent[u][0];
72        };
73
74        vector<int> power;
75        int MOD = 1e9 + 7;
76        power.push_back(1);
77        int val = 1;
78        
79        for(int i = 1; i <= 1e5; i++) {
80            val = (2LL * val) % MOD;
81            power.push_back(val);
82        }
83
84
85        vector<int> res;
86        for(auto &q : queries) {
87            int u = q[0], v = q[1];
88            int w = findLCA(u, v);
89
90            int distance = depth[u] + depth[v] - 2 * depth[w];
91            if(distance == 0) {
92                res.push_back(0); 
93                continue; 
94            }
95            res.push_back(power[distance - 1]);
96        }
97        return res;
98    }   
99};