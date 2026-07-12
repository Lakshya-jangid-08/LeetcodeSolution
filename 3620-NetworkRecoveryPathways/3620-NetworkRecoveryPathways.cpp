// Last updated: 7/12/2026, 6:28:44 PM
1class unionSet {
2 public:
3    vector<int> parent, size, mnw;
4
5    unionSet(int n) : parent(n + 1), size(n + 1, 1), mnw(n + 1, 1e9) {
6        iota(parent.begin(), parent.end(), 0);
7    }
8
9    int findPar(int x) {
10        if(parent[x] == x) return x;
11        return parent[x] = findPar(parent[x]);
12    }
13
14    void join(int u, int v, int w) {
15        int pu = findPar(u), pv = findPar(v);
16        if(pu == pv){
17            mnw[pu] = mnw[pv] = min(mnw[pu], w);
18            return;
19        }
20
21        if(size[pu] < size[pv]) {
22            size[pv] += size[pu];
23            parent[pu] = pv;
24        } else {
25            parent[pv] = pu;
26            size[pu] += size[pv];
27        }
28        int minW = min({mnw[pv], mnw[pu], w});
29        mnw[pv] = mnw[pu] = minW;
30        return;
31    }
32
33    int solution() {
34        return mnw[findPar(1)];
35    }
36};
37
38class Solution {
39 public:
40    int minScore(int n, vector<vector<int>>& roads) {
41        
42        unionSet ds(n);
43
44        for(const auto &road : roads) {
45            const int u = road[0], v = road[1], w = road[2];
46            ds.join(u, v, w);
47        }
48
49        return ds.solution();
50
51    }
52};