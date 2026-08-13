// Last updated: 8/13/2026, 11:44:39 AM
1class NumArray {
2    vector<int> seg, lazy;
3    int n;
4
5public:
6    NumArray(vector<int>& nums) : n(nums.size()), seg(4 * nums.size() + 1, 0), lazy(4 * nums.size() + 1, 0) {
7        build(nums, 0, 0, n - 1);
8    }
9
10    void build(vector<int>& nums, int idx, int l, int r) {
11        if (l == r) {
12            seg[idx] = nums[l];
13            return;
14        }
15
16        int mid = (l + r) / 2;
17
18        build(nums, 2 * idx + 1, l, mid);
19        build(nums, 2 * idx + 2, mid + 1, r);
20
21        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
22    }
23
24    // Apply pending lazy value to current node
25    void push(int idx, int l, int r) {
26        if (lazy[idx] == 0)
27            return;
28
29        // Add lazy value to the whole segment
30        seg[idx] += (r - l + 1) * lazy[idx];
31
32        // Propagate to children
33        if (l != r) {
34            lazy[2 * idx + 1] += lazy[idx];
35            lazy[2 * idx + 2] += lazy[idx];
36        }
37
38        lazy[idx] = 0;
39    }
40
41    // Range update:
42    // Add val to every element in [ql, qr]
43    void updateRange(int idx, int ql, int qr, int val, int l, int r) {
44
45        // First apply pending updates
46        push(idx, l, r);
47
48        // No overlap
49        if (qr < l || r < ql)
50            return;
51
52        // Complete overlap
53        if (ql <= l && r <= qr) {
54            lazy[idx] += val;
55            push(idx, l, r);
56            return;
57        }
58
59        int mid = (l + r) / 2;
60
61        updateRange(2 * idx + 1, ql, qr, val, l, mid);
62        updateRange(2 * idx + 2, ql, qr, val, mid + 1, r);
63
64        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
65    }
66
67    // Point update: nums[index] = val
68    void update(int index, int val) {
69        updatePoint(0, index, val, 0, n - 1);
70    }
71
72    void updatePoint(int idx, int i, int val, int l, int r) {
73        push(idx, l, r);
74
75        if (l == r) {
76            seg[idx] = val;
77            return;
78        }
79
80        int mid = (l + r) / 2;
81
82        if (i <= mid)
83            updatePoint(2 * idx + 1, i, val, l, mid);
84        else
85            updatePoint(2 * idx + 2, i, val, mid + 1, r);
86
87        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
88    }
89
90    // Range sum query
91    int sumRange(int left, int right) {
92        return query(0, left, right, 0, n - 1);
93    }
94
95    int query(int idx, int ql, int qr, int l, int r) {
96        push(idx, l, r);
97
98        // No overlap
99        if (qr < l || r < ql)
100            return 0;
101
102        // Complete overlap
103        if (ql <= l && r <= qr)
104            return seg[idx];
105
106        int mid = (l + r) / 2;
107
108        return query(2 * idx + 1, ql, qr, l, mid) + query(2 * idx + 2, ql, qr, mid + 1, r);
109    }
110};