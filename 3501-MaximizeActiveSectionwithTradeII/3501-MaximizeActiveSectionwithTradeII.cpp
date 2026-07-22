// Last updated: 7/22/2026, 11:27:36 AM
1class SegmentTree {
2    vector<int> tree;
3    int n;
4
5    private:void build(int idx, int l, int r, vector<int> & nums) {
6        if(l == r) {
7            tree[idx] = nums[l];
8            return;
9        }
10        int mid = (l + r) / 2;
11        build(2 * idx + 1, l, mid, nums);
12        build(2 * idx + 2, mid + 1, r, nums);
13
14        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
15    }
16
17    private:int query(int idx, int l, int r, int ql, int qr) {
18        if (ql <= l && r <= qr)
19            return tree[idx];
20
21        int mid = (l + r) >> 1;
22        int ans = 0;
23
24        if (ql <= mid)
25            ans = max(ans, query((idx << 1) + 1, l, mid, ql, qr));
26
27        if (qr > mid)
28            ans = max(ans, query((idx << 1) + 2, mid + 1, r, ql, qr));
29
30        return ans;
31    }
32
33    public: SegmentTree(vector<int> & nums) {
34        n = nums.size();
35        tree.assign(4 * n, 0);
36        build(0, 0, n - 1, nums);
37    }
38
39    public:int query(int l, int r) {
40        if (l > r || n == 0)
41            return 0;
42
43        return query(0, 0, n - 1, l, r);
44    }
45
46};
47
48class Solution {
49public:
50    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
51        // calculated curr Active Section
52        // => After that for Q * check N
53        int n = s.length();
54
55        int currActive = count(s.begin(), s.end(), '1');
56        vector<int> zeroLen, left, right;
57        
58        int i = 0;
59        while(i < n) {
60            int j = i;
61
62            while(j < n && s[j] == s[i]) j++;
63
64            if(s[i] == '0') {
65                zeroLen.push_back(j - i);
66                left.push_back(i);
67                right.push_back(j - 1);
68            }
69
70            i = j;
71        }
72
73        int m = zeroLen.size();
74        int q = queries.size();
75
76        if(m < 2) return vector<int>(q, currActive);
77
78        vector<int> gain(m - 1);
79        for(int i = 0; i < m - 1; i++) {
80            gain[i] = zeroLen[i] + zeroLen[i + 1];
81        }
82
83        SegmentTree st(gain);
84
85        vector<int> ans;
86        for(int i = 0; i < q; i++) {
87            int l = queries[i][0], r = queries[i][1];
88            int firstZero = lower_bound(right.begin(), right.end(), l) - right.begin();
89            int lastZero = upper_bound(left.begin(), left.end(), r) - left.begin() - 1;
90
91            if(lastZero <= firstZero || firstZero >= m || lastZero < 0) {
92                ans.push_back(currActive);
93                continue;
94            }
95
96            int firstLen = right[firstZero] - max(left[firstZero], l) + 1;
97            int lastLen = min(right[lastZero], r) - left[lastZero] + 1;
98
99            if(firstZero + 1 == lastZero) {
100                ans.push_back(currActive + firstLen + lastLen);
101                continue;
102            }
103
104            int best = 0;
105
106            best = max(best, firstLen + zeroLen[firstZero + 1]);
107            best = max(best, lastLen + zeroLen[lastZero - 1]);
108            best = max(best, st.query(firstZero + 1, lastZero - 2));
109            ans.push_back(best + currActive);
110        }
111        return ans;
112    }
113};