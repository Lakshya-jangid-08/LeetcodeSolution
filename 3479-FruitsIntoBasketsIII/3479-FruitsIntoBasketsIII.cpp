// Last updated: 8/14/2026, 10:41:28 AM
1class Solution {
2public:
3    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
4        int n = f.size(), m = b.size();
5        vector<int> seg(4 * m);
6
7        const auto build = [&](auto &&self, int idx, int l, int r) -> void {
8            if(l == r) {
9                seg[idx] = b[l];
10                return;
11            }
12            int mid = (l + r) / 2;
13
14            self(self, 2 * idx + 1, l, mid);
15            self(self, 2 * idx + 2, mid + 1, r);
16
17            seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
18        };
19        build(build, 0, 0, m - 1);
20
21        const auto search = [&](auto &&self, int idx, int l, int r, int v) -> int {
22            if(seg[idx] < v) return -1;
23            if(l == r) {
24                if(seg[idx] >= v) {
25                    seg[idx] = -1;
26                    return l;
27                }
28                return -1;
29            }
30            int mid = (l + r) / 2;
31            int placedIdx = self(self, 2 * idx + 1, l, mid, v);
32            if(placedIdx == -1) {
33                placedIdx = self(self, 2 * idx + 2, mid + 1, r, v);
34            }
35            seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
36            return placedIdx;
37        };
38
39        int count = 0;
40        for(int i = 0; i < n; i++) {
41            if(search(search, 0, 0, m - 1, f[i]) == -1) count += 1;
42        }
43        return count;
44    }
45};