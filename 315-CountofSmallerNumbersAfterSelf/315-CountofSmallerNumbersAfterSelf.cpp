// Last updated: 8/15/2026, 12:22:25 PM
1class Solution {
2public:
3    vector<int> countSmaller(vector<int>& nums) {
4        int n = nums.size();
5        vector<vector<int>> seg(4 * n + 1);
6
7        const auto merge = [](vector<int> &p, vector<int> &q, vector<int> &res) -> void {
8
9            int i = 0, j = 0, n = p.size(), m = q.size();
10            int k = 0;
11            while(i < n && j < m) {
12                if(p[i] < q[j]) res.push_back(p[i++]);
13                else res.push_back(q[j++]);
14            }
15            while(i < n) {
16                res.push_back(p[i++]);
17            }
18            while(j < m) {
19                res.push_back(q[j++]);
20            }
21        };
22
23        auto const build = [&](auto &&self, int idx, int l, int r) -> void {
24            if(l == r) {
25                seg[idx].push_back(nums[r]);
26                return;
27            }
28            int mid = (l + r) / 2;
29
30            self(self, 2 * idx + 1, l, mid);
31            self(self, 2 * idx + 2, mid + 1, r);
32
33            merge(seg[2 * idx + 1], seg[2 * idx + 2], seg[idx]);
34        };
35        build(build, 0, 0, n - 1);
36
37        const auto countSmallNums = [&](auto &&self, int idx, int l, int r, int ql, int qr, int v) -> int {
38            if(l > qr || r < ql)
39                return 0;
40
41            if(ql <= l && r <= qr) {
42                int k = lower_bound(seg[idx].begin(), seg[idx].end(), v) - seg[idx].begin();
43                return k;
44            }
45
46            int mid = (l + r) / 2;
47            int left = self(self, 2 * idx + 1, l, mid, ql, qr, v);
48            int right = self(self, 2 * idx + 2, mid + 1, r, ql, qr, v);
49
50            return left +  right;
51        };
52
53        vector<int> res;
54        for(int i = 0; i < n - 1; i++) {
55            int v = nums[i];
56            int cnt = countSmallNums(countSmallNums, 0, 0, n - 1, i + 1, n - 1, v);
57            res.push_back(cnt);
58        }
59        res.push_back(0);
60        return res;
61    }
62};