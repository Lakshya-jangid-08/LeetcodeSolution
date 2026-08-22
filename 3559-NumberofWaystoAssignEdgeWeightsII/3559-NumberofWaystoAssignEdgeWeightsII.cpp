// Last updated: 8/22/2026, 11:45:18 AM
1class Solution {
2public:
3    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
4        int n = edges.size() + 1;
5        int col = log2(n) + 1;
6
7        vector<vector<int>> parent(n + 1, vector<int>(col, -1));
8        vector<int> depth(n + 1, 0);
9        vector<vector<int>> adj(n + 1);
10
11        for (auto &ed : edges) {
12            int u = ed[0], v = ed[1];
13            adj[u].push_back(v);
14            adj[v].push_back(u);
15        }
16
17        // DFS
18        // O(N + E) = O(N), since E = N - 1
19        vector<bool> visit(n + 1, false);
20
21        const auto dfs = [&](auto &&func, int node, int par, int d = 0) {
22            if (visit[node]) return;
23
24            visit[node] = true;
25            parent[node][0] = par;
26            depth[node] = d;
27
28            for (auto &nextNode : adj[node]) {
29                func(func, nextNode, node, d + 1);
30            }
31        };
32
33        dfs(dfs, 1, -1);
34
35        // Binary lifting table
36        // O(N log N)
37        for (int i = 1; i < col; ++i) {
38            for (int node = 1; node <= n; ++node) {
39                int mid = parent[node][i - 1];
40
41                if (mid != -1) {
42                    parent[node][i] = parent[mid][i - 1];
43                }
44            }
45        }
46
47        // Find kth ancestor
48        // O(log N)
49        const auto findKthAncestor = [&](int node, int k) -> int {
50            for (int i = col - 1; i >= 0; --i) {
51                if (k & (1 << i)) {
52                    node = parent[node][i];
53                    if(node == -1) return -1;
54                }
55            }
56
57            return node;
58        };
59
60        // Find LCA
61        // O(log N)
62        const auto findLCA = [&](int u, int v) -> int {
63            // Make depths equal
64            if (depth[u] > depth[v]) {
65                u = findKthAncestor(u, depth[u] - depth[v]);
66            } 
67            else if (depth[v] > depth[u]) {
68                v = findKthAncestor(v, depth[v] - depth[u]);
69            }
70
71            if (u == v) {
72                return u;
73            }
74
75            // Move both nodes upward
76            for (int i = col - 1; i >= 0; --i) {
77                if (parent[u][i] != parent[v][i]) {
78                    u = parent[u][i];
79                    v = parent[v][i];
80                }
81            }
82
83            return parent[u][0];
84        };
85
86        // Precompute powers of 2
87        const int MOD = 1'000'000'007;
88        const int MAX_DISTANCE = 100'000;
89
90        vector<int> power(MAX_DISTANCE + 1, 1);
91
92        for (int i = 1; i <= MAX_DISTANCE; ++i) {
93            power[i] = (2LL * power[i - 1]) % MOD;
94        }
95
96        // Answer queries
97        // O(Q log N)
98        vector<int> res;
99        res.reserve(queries.size());
100
101        for (auto &q : queries) {
102            int u = q[0];
103            int v = q[1];
104
105            int lca = findLCA(u, v);
106
107            int distance = depth[u] + depth[v] - 2 * depth[lca];
108
109            if (distance == 0) {
110                res.push_back(0);
111            } else {
112                res.push_back(power[distance - 1]);
113            }
114        }
115
116        return res;
117    }
118};