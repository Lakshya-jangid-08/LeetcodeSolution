// Last updated: 7/12/2026, 12:21:30 PM
1
2struct node {
3    long long weight;
4    int num;
5
6    bool operator<(const node& other) const {
7        return weight > other.weight;
8    }
9
10};
11
12class Solution {
13public:
14    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
15        // DAG - toposort 
16        // Dijsktra
17        int n = online.size();
18        vector<vector<pair<int,int>>> adj(n);
19
20        int mxw = -1, mnw = 1e9 + 1; 
21
22        for(const auto & ed : edges) {
23            int u = ed[0], v = ed[1], w = ed[2];
24            if(online[u] && online[v]) {
25                mxw = max(mxw, w);
26                mnw = min(mnw, w);
27                adj[u].push_back({v,w});
28            }
29        }
30
31        // min should be maximum
32
33        const auto isPos = [&](int minw) -> bool {
34            vector<long long> dist(n, LLONG_MAX);
35            priority_queue<node> pq;
36            pq.push({0LL, 0});
37
38            dist[0] = 0;
39
40            while(!pq.empty()) {
41
42                auto topNode = pq.top(); pq.pop();
43                long long weight = topNode.weight; 
44                int num = topNode.num;
45
46                if(weight > dist[num]) continue;
47                if(num == n-1) return true;
48
49                for(const auto &[nextNum, w] : adj[num]) {
50                    if(1LL * w + weight > 1LL * k) continue;
51                    if(w < minw) continue;
52                    if(dist[nextNum] < dist[num] + w) continue;
53                    dist[nextNum] = dist[num] + w;
54                    pq.push({1LL * w + weight, nextNum});
55                }
56
57            }   
58            return false;
59        };
60
61        if(!isPos(0)) return -1;
62
63        int res = -1;
64        while(mxw >= mnw) {
65            int mid = (mxw) - (mxw - mnw) / 2;
66            if(isPos(mid)) {
67                mnw = mid + 1;
68                res = mid;
69            } else {
70                mxw = mid - 1;
71            }
72        }
73
74        return res;
75    }
76};