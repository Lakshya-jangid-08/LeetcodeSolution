// Last updated: 8/21/2026, 2:04:55 AM
1class Solution {
2    void solve(vector<int> & nums, vector<int>& res, int idx, int sum) {
3        if(idx == nums.size()) {
4            res.push_back(sum);
5            return;
6        }
7
8        solve(nums, res, idx + 1, sum);
9        solve(nums, res, idx + 1, sum + nums[idx]);
10
11    }
12public:
13    int minAbsDifference(vector<int>& nums, int goal) {
14        // sum - goal closetsum
15        int n = nums.size();
16        int m = n / 2;
17        vector<int> left(m), right(n - m);
18
19        for(int i = 0; i < m; i++) {
20            left[i] = nums[i];
21        }
22        for(int i = m; i < n; i++) {
23            right[i - m] = nums[i];
24        }
25
26        vector<int> l, r;
27        solve(left, l, 0, 0);
28        solve(right, r, 0, 0);
29
30        sort(l.begin(), l.end());
31        sort(r.begin(), r.end());
32
33        long long res = 1e15;
34
35        for(int i = 0; i < l.size(); i++) {
36
37            int diff = goal - l[i];
38
39            int idx = lower_bound(r.begin(), r.end(), diff) - r.begin();
40
41            if(idx > 0) {
42                res = min(res, 1LL * abs(goal - l[i] - r[idx - 1]));
43            }
44            if(idx < r.size()) {
45                res = min(res, 1LL * abs(goal - l[i] - r[idx]));
46            }
47
48        }
49        return res;
50    }
51};