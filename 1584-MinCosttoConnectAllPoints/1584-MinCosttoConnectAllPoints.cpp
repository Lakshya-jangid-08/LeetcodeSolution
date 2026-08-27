// Last updated: 8/27/2026, 11:56:36 PM
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
39
40        for(int i = 0; i < points.size(); i++) {
41            for(int j =  i + 1; j < points.size(); j++) {
42
43                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
44                distances.push_back({i, j, d});
45            }   
46        }
47
48
49        sort(distances.begin(), distances.end(), [](auto &d1, auto &d2) {
50            return d1[2] < d2[2];
51        });
52        int n = distances.size();
53        DisjointSet dsu(points.size() + 1);
54        int cost = 0;
55        for(int i = 0; i < n; i++) {
56            int u = distances[i][0], v = distances[i][1], w = distances[i][2];
57            if(dsu.join(u, v)) cost += w;
58        }
59        return cost;
60    }
61};