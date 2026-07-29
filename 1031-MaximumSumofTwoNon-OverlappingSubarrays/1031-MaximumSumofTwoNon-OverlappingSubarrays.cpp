// Last updated: 7/29/2026, 12:25:21 PM
1class Solution {
2public:
3    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
4        int n = nums.size();
5
6        vector<int> ps(n + 1, 0);
7        for(int i = 0; i < n; i++) {
8            ps[i + 1] = ps[i] + nums[i];
9        }
10
11        int res = 0;
12        auto calc = [&](int lenA, int lenB) {
13            int best = 0;
14            for (int i = lenA; i <= n - lenB; i++) {
15                best = max(best, ps[i] - ps[i - lenA]);
16                res = max(res, best + ps[lenB + i] - ps[i]);
17
18            }
19        };
20
21        calc(firstLen, secondLen);
22        calc(secondLen, firstLen);
23
24        return res;
25    }   
26};