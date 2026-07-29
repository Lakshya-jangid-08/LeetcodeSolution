// Last updated: 7/29/2026, 12:16:57 PM
1class Solution {
2public:
3    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
4        int n = nums.size();
5        vector<int> ps1(n, 0), ps2(n, 0);
6
7        const auto insertValues = [&](int len, vector<int> & ps) -> void {
8            int idx = 0, r = 0, l = 0;
9            while(r < len) {
10                ps[idx] += nums[r++]; 
11            }
12            idx++;
13            while(r < n) {
14                ps[idx] = ps[idx - 1] + nums[r] - nums[l];
15                l++; r++; idx++;
16            }
17        };
18
19        int res = 0;
20
21        auto calc = [&](vector<int>& A, int lenA, vector<int>& B, int lenB) {
22            int best = 0;
23            for (int i = lenA; i < B.size(); i++) {
24                best = max(best, A[i - lenA]);
25                res = max(res, best + B[i]);
26            }
27        };
28
29        insertValues(firstLen, ps1);
30        insertValues(secondLen, ps2);
31
32        calc(ps1, firstLen, ps2, secondLen);
33        calc(ps2, secondLen, ps1, firstLen);
34
35        return res;
36    }   
37};