// Last updated: 8/13/2026, 2:04:51 PM
1class Solution {
2public:
3    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& queries) {
4        int n = h.size();
5        vector<int> seg(4*n + 1, 0);
6        
7        auto const build = [&](auto &&self, int idx, int l, int r) -> void {
8            if(l == r) {
9                seg[idx] = h[l];
10                return;
11            }
12            int mid = (l + r) / 2;
13
14            self(self, 2 * idx + 1, l, mid);
15            self(self, 2 * idx + 2, mid + 1, r);
16
17            seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
18        };
19        build(build, 0, 0, n - 1);
20
21        const auto isBigger = [&](auto &&self, int idx, int l, int r, int ql, int qr, int v) -> int {
22            if(l > qr || r < ql)
23                return -1;
24
25            if(l == r) {
26                return (v >= seg[idx]) ? -1 : l;
27            }
28            if (seg[idx] <= v)
29                return -1;
30            
31            int mid = (l + r) / 2;
32            int left = self(self, 2 * idx + 1, l, mid, ql, qr, v);
33            if(left != -1) return left;
34            int right = self(self, 2 * idx + 2, mid + 1, r, ql, qr, v);
35
36            return right;
37        };
38
39        vector<int> res;
40        for(auto q : queries) {
41            int ql = q[0], qr = q[1];
42            if(ql > qr) swap(ql, qr);
43            int alice = h[ql], bob = h[qr];
44            if(alice < bob || ql == qr) {
45                res.push_back(qr);
46                continue;
47            }
48
49            int v = isBigger(isBigger, 0, 0, n - 1, qr, n - 1, max(alice, bob));
50            res.push_back(v);
51        }
52        return res;
53    }
54};