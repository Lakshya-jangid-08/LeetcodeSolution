// Last updated: 8/30/2026, 12:41:57 AM
1class Solution {
2    vector<int> parent;
3    vector<int> size;
4
5    int findPar(int x) {
6        if(x == parent[x]) return x;
7        return parent[x] = findPar(parent[x]);
8    }
9
10    void join(int u, int v) {
11        int pu = findPar(u);
12        int pv = findPar(v);
13
14        if(pu == pv) return;
15
16        if(size[pu] < size[pv]) {
17            parent[pu] = pv;
18            size[pv] += size[pu];
19        } else {
20            parent[pv] = pu;
21            size[pu] += size[pv];
22        }
23    }
24
25 public:
26    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
27        int n = nums.size();
28        parent = vector<int>(n, 0);
29        size = vector<int>(n, 0);
30        iota(parent.begin(), parent.end(), 0);
31
32        vector<pair<int, int>> temp;
33        for(int i = 0; i < n; i++) {
34            temp.push_back({nums[i], i});
35        }
36
37        sort(temp.begin(), temp.end());
38
39        for(int i = 0; i < n - 1; i++) {
40            auto &[v1, idx1] = temp[i];
41            auto &[v2, idx2] = temp[i + 1];
42            
43            if(v2 - v1 <= limit) {
44                join(idx1, idx2);
45            }
46        }
47
48        unordered_map<int , vector<int>> mp;
49
50        for(int i = n - 1; i >= 0; i--) {
51            int par = findPar(i);
52            mp[par].push_back(i);
53        }
54
55        for(auto &[_, arr] : mp) {
56            sort(arr.begin(), arr.end(), [&](auto &idx1, auto &idx2) {
57                return nums[idx1] > nums[idx2];
58            });
59        }
60
61        vector<int> res(n);
62        for(int i = 0; i < n; i++) {
63            int par = findPar(i);
64
65            int idx = mp[par].back();
66            mp[par].pop_back(); 
67
68            res[i] = nums[idx];
69        }
70        return res;
71     }
72};