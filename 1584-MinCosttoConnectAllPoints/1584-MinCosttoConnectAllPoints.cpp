// Last updated: 8/28/2026, 12:27:45 AM
1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        vector<vector<pair<int, int>>> adj(n + 1);
5
6        for(int i = 0; i < times.size(); i++) {
7            int u = times[i][0], v = times[i][1], w = times[i][2];
8            adj[u].push_back({v, w});
9        }
10
11
12
13        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> q;
14
15        q.push({0, k});
16        int maxCost = 0;
17        unordered_set<int> ust;
18
19        while(!q.empty()) {
20            int len = q.size();
21            while(len--) {
22                auto [cost, u] = q.top(); q.pop();
23                if(ust.find(u) != ust.end()) continue;
24                maxCost = max(maxCost, cost);
25                ust.insert(u);
26                for(auto &[v, w] : adj[u]) {
27                    q.push({cost + w, v});
28                }
29            }
30        }
31        return (ust.size() == n) ? maxCost : -1; 
32
33    }
34};