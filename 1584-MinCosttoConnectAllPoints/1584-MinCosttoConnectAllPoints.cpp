// Last updated: 8/27/2026, 11:37:42 PM
1class DisjointSet {
2
3    vector<int> parent;
4    vector<int> size;
5    public :
6    DisjointSet(int n) {
7        parent.resize(n, 0);
8        size.resize(n, 0);
9        iota(parent.begin(), parent.end(), 0);
10    }
11
12    int findPar(int x) {
13        if(parent[x] == x) return x;
14        return parent[x] = findPar(parent[x]); 
15    }
16
17    bool join(int u, int v) {
18        int pu = findPar(u);
19        int pv = findPar(v);
20
21        if (pu == pv) return false;
22
23        if (size[pu] < size[pv]) {
24            parent[pu] = pv;
25            size[pv] += size[pu];
26        } else {
27            parent[pv] = pu;
28            size[pu] += size[pv];
29        }
30        return true;
31    }
32
33};
34
35class Solution {
36public:
37    int minCostConnectPoints(vector<vector<int>>& points) {
38        vector<vector<int>> distances;
39        unordered_map<string, int> mp;
40        int idx = 0;
41        for(int i = 0; i < points.size(); i++) {
42            for(int j =  i + 1; j < points.size(); j++) {
43                string u = to_string(points[i][0]) + " " + to_string(points[i][1]);
44                string v = to_string(points[j][0]) + " " + to_string(points[j][1]);
45
46                if(!mp.count(u)) mp[u] = idx++;
47                if(!mp.count(v)) mp[v] = idx++;
48
49                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
50                distances.push_back({mp[u], mp[v], d});
51            }   
52        }
53
54
55        sort(distances.begin(), distances.end(), [](auto &d1, auto &d2) {
56            return d1[2] < d2[2];
57        });
58        int n = distances.size();
59        DisjointSet dsu(idx + 1);
60        int cost = 0;
61        for(int i = 0; i < n; i++) {
62            int u = distances[i][0], v = distances[i][1], w = distances[i][2];
63            if(dsu.join(u, v)) cost += w;
64        }
65        return cost;
66    }
67};