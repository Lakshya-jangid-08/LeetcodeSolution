// Last updated: 8/14/2026, 9:57:00 AM
1class Solution {
2    struct Node {
3        int maxLen;
4        int len;
5        int pl;
6        int sl;
7        char pc;
8        char sc;
9        Node() : len(0), maxLen(0), pl(0), sl(0), pc('_'), sc('_') {;}
10    };
11public:
12    vector<int> longestRepeating(string s, string qc, vector<int>& qidx) {
13        int n = s.length();
14        vector<Node> seg(4 * n + 1);
15
16        const auto merge = [&](Node left, Node right) -> Node {
17            if(left.len == 0) return right;
18            if(right.len == 0) return left;
19            Node res;
20
21            res.len = right.len + left.len;
22            res.pc = left.pc;
23            res.sc = right.sc;
24
25            res.pl = left.pl;
26
27            if(left.pl == left.len && right.pc == left.sc) {
28                res.pl += right.pl;
29            }
30
31            res.sl = right.sl;
32            if(right.sl == right.len && right.pc == left.sc) {
33                res.sl += left.sl;
34            }
35
36            res.maxLen = max(left.maxLen, right.maxLen);
37            if(right.pc == left.sc) {
38                res.maxLen = max(res.maxLen, right.pl + left.sl);
39            }
40            return res;
41        };
42
43        const auto build = [&](auto &&self, int l, int r, int idx) -> Node {
44            if (l == r) {
45                seg[idx].len = 1;
46                seg[idx].maxLen = 1;
47                seg[idx].pl = 1;
48                seg[idx].sl = 1;
49                seg[idx].pc = s[l];
50                seg[idx].sc = s[l];
51
52                return seg[idx];
53            }
54
55            int mid = (l + r) / 2;
56            auto left = self(self, l, mid, 2 * idx + 1);
57            auto right = self(self, mid + 1, r, 2 * idx + 2);
58        
59            return seg[idx] = merge(left, right);
60        };
61        build(build, 0, n - 1, 0);
62
63        const auto update = [&](auto &&self, int l, int r, int idx, int update_idx, char v) {
64            if (l == r) {
65                seg[idx].len = 1;
66                seg[idx].maxLen = 1;
67                seg[idx].pl = 1;
68                seg[idx].sl = 1;
69                seg[idx].pc = v;
70                seg[idx].sc = v;
71
72                return;
73            }
74
75            int mid = (l + r) / 2;
76            if(update_idx <= mid) self(self, l, mid, 2 * idx + 1, update_idx, v);
77            else self(self, mid + 1, r, 2 * idx + 2, update_idx, v);
78            Node left = seg[2 * idx + 1], right = seg[2 * idx + 2];
79        
80            seg[idx] = merge(left, right);
81        };
82
83        vector<int> res;
84
85        int q = qc.length();
86        for(int i = 0; i < q; i++) {
87            char c = qc[i];
88            int idx = qidx[i];
89            update(update, 0, n -1, 0, idx, c);
90            res.push_back(seg[0].maxLen);
91        }
92    
93        return res;
94
95    }
96};