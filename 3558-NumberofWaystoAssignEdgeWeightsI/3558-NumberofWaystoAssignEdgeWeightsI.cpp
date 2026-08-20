// Last updated: 8/20/2026, 7:34:53 PM
1class Solution {
2public:
3    int assignEdgeWeights(vector<vector<int>>& edges) {
4        int n = edges.size();
5        vector<vector<int>> adj(n + 2);
6
7        for(auto &e : edges) {
8            adj[e[0]].push_back(e[1]);
9            adj[e[1]].push_back(e[0]);
10        }
11
12        vector<int> visit(n + 2, 0);
13        const auto maxDepth = [&](auto && md, int root) -> int {
14            if(visit[root]) return -1e8;
15            visit[root] = 1;
16
17            int d = 0;
18            for(auto next : adj[root]) {
19                d = max(d, 1 + md(md, next));
20            }
21
22            return d;
23        };
24
25        int depth = maxDepth(maxDepth, 1);
26        
27        const int MOD = 1e9 + 7;
28        long long res = 1;
29
30        for(int i = 0; i < depth-1; i++) {
31            res = (2LL * res);
32            res = res % MOD;
33        }
34        return res;
35    }
36};